/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
TremoloAudioProcessor::TremoloAudioProcessor()
#ifndef JucePlugin_PreferredChannelConfigurations
     : AudioProcessor (BusesProperties()
                     #if ! JucePlugin_IsMidiEffect
                      #if ! JucePlugin_IsSynth
                       .withInput  ("Input",  juce::AudioChannelSet::stereo(), true)
                      #endif
                       .withOutput ("Output", juce::AudioChannelSet::stereo(), true)
                     #endif
                       ),
        treeState(*this, nullptr, "PARAMETERS", createParameterLayout())
#endif
{
    //add Listener to Parameters (nesseary for parameterChanged() )
    treeState.addParameterListener(RATE_ID, this);
    treeState.addParameterListener(PHASE_ID, this);
    treeState.addParameterListener(DEPTH_ID, this);
    treeState.addParameterListener(BYPASS_ID, this);
    
}

TremoloAudioProcessor::~TremoloAudioProcessor()
{
    treeState.removeParameterListener(RATE_ID, this);
    treeState.removeParameterListener(PHASE_ID, this);
    treeState.removeParameterListener(DEPTH_ID, this);
    treeState.removeParameterListener(BYPASS_ID, this);
}

juce::AudioProcessorValueTreeState::ParameterLayout TremoloAudioProcessor::createParameterLayout()
{
    std::vector<std::unique_ptr<juce::RangedAudioParameter>> params;
    
    auto paramRate = std::make_unique<juce::AudioParameterFloat>(RATE_ID, RATE_NAME, 0.0, 20.0, 1.0);
    auto paramPhase = std::make_unique<juce::AudioParameterInt>(PHASE_ID, PHASE_NAME, -180.0, 180.0, 0.0);
    auto paramDepth = std::make_unique<juce::AudioParameterInt>(DEPTH_ID, DEPTH_NAME, 0.0, 100.0, 100.0);
    auto paramBypass = std::make_unique<juce::AudioParameterBool>(BYPASS_ID, BYPASS_NAME, true);
    
    params.push_back(std::move(paramRate));
    params.push_back(std::move(paramPhase));
    params.push_back(std::move(paramDepth));
    params.push_back(std::move(paramBypass));
    
    return { params.begin(), params.end()};
}

//==============================================================================
const juce::String TremoloAudioProcessor::getName() const
{
    return JucePlugin_Name;
}

bool TremoloAudioProcessor::acceptsMidi() const
{
   #if JucePlugin_WantsMidiInput
    return true;
   #else
    return false;
   #endif
}

bool TremoloAudioProcessor::producesMidi() const
{
   #if JucePlugin_ProducesMidiOutput
    return true;
   #else
    return false;
   #endif
}

bool TremoloAudioProcessor::isMidiEffect() const
{
   #if JucePlugin_IsMidiEffect
    return true;
   #else
    return false;
   #endif
}

double TremoloAudioProcessor::getTailLengthSeconds() const
{
    return 0.0;
}

int TremoloAudioProcessor::getNumPrograms()
{
    return 1;   // NB: some hosts don't cope very well if you tell them there are 0 programs,
                // so this should be at least 1, even if you're not really implementing programs.
}

int TremoloAudioProcessor::getCurrentProgram()
{
    return 0;
}

void TremoloAudioProcessor::setCurrentProgram (int index)
{
}

const juce::String TremoloAudioProcessor::getProgramName (int index)
{
    return {};
}

void TremoloAudioProcessor::changeProgramName (int index, const juce::String& newName)
{
}

//==============================================================================
void TremoloAudioProcessor::prepareToPlay (double sampleRate, int samplesPerBlock)
{
    // Use this method as the place to do any pre-playback
    // initialisation that you need..
    
    spec.maximumBlockSize = samplesPerBlock;
    spec.sampleRate = sampleRate;
    spec.numChannels = getTotalNumOutputChannels();
    
    time = 0.0;
}

void TremoloAudioProcessor::releaseResources()
{
    // When playback stops, you can use this as an opportunity to free up any
    // spare memory, etc.
}

#ifndef JucePlugin_PreferredChannelConfigurations
bool TremoloAudioProcessor::isBusesLayoutSupported (const BusesLayout& layouts) const
{
  #if JucePlugin_IsMidiEffect
    juce::ignoreUnused (layouts);
    return true;
  #else
    // This is the place where you check if the layout is supported.
    // In this template code we only support mono or stereo.
    // Some plugin hosts, such as certain GarageBand versions, will only
    // load plugins that support stereo bus layouts.
    if (layouts.getMainOutputChannelSet() != juce::AudioChannelSet::mono()
     && layouts.getMainOutputChannelSet() != juce::AudioChannelSet::stereo())
        return false;

    // This checks if the input layout matches the output layout
   #if ! JucePlugin_IsSynth
    if (layouts.getMainOutputChannelSet() != layouts.getMainInputChannelSet())
        return false;
   #endif

    return true;
  #endif
}
#endif

void TremoloAudioProcessor::parameterChanged(const juce::String &parameterID, float newValue)
{
    if(parameterID == RATE_ID){
        paramRateVal = newValue;
    }
    if(parameterID == PHASE_ID){
        paramPhaseVal = newValue;
    }
    if(parameterID == DEPTH_ID){
        paramDepthVal = newValue;
    }
    if(parameterID == BYPASS_ID){
        paramBypassVal = newValue;
    }
}

void TremoloAudioProcessor::processBlock (juce::AudioBuffer<float>& buffer, juce::MidiBuffer& midiMessages)
{
    juce::ScopedNoDenormals noDenormals;
    auto totalNumInputChannels  = getTotalNumInputChannels();
    auto totalNumOutputChannels = getTotalNumOutputChannels();

    // In case we have more outputs than inputs, this code clears any output
    // channels that didn't contain input data, (because these aren't
    // guaranteed to be empty - they may contain garbage).
    // This is here to avoid people getting screaming feedback
    // when they first compile a plugin, but obviously you don't need to keep
    // this code if your algorithm always overwrites all the output channels.
    for (auto i = totalNumInputChannels; i < totalNumOutputChannels; ++i)
        buffer.clear (i, 0, buffer.getNumSamples());

    // This is the place where you'd normally do the guts of your plugin's
    // audio processing...
    // Make sure to reset the state if your inner loop is processing
    // the samples and the outer loop is handling the channels.
    // Alternatively, you can process the samples with the channels
    // interleaved by keeping the same state.
    
    for (int i = totalNumInputChannels; i < totalNumOutputChannels; ++i)
        buffer.clear (i, 0, buffer.getNumSamples());
    
    float freq = paramRateVal;
    float sampleRate = spec.sampleRate; //float sampleRate = 44100;
    float twoPi = juce::MathConstants<float>::twoPi;
    float halfPi = juce::MathConstants<float>::halfPi;
    float w = twoPi * freq;
    float mod;
    float timePerOsc = 1/freq;
    
    float t = 1/sampleRate;
    
    if(paramBypassVal){
        for(int sample = 0; sample < buffer.getNumSamples(); ++sample){
            float phase = 0.0;
            if(paramPhaseVal >= 0.0){
                
                phase = 0;
                
                for(int ch = 0; ch < totalNumInputChannels; ++ch){
                    auto* chData = buffer.getWritePointer(ch);
                    mod = (sin( w * time - halfPi + (phase/360 * twoPi )) + 1) / 2;
                    if(paramDepthVal != 0 && freq != 0){
                        chData[sample] *= mod * (paramDepthVal/100) + (1-(paramDepthVal/100));
                    }
                    
                    phase = phase + paramPhaseVal;
                }
            }else{
                
                phase = paramPhaseVal * totalNumInputChannels;
                
                for(int ch = totalNumInputChannels-1; ch >= 0; --ch){
                    auto* chData = buffer.getWritePointer(ch);
                    mod = (sin( w * time - halfPi + (phase/360 * twoPi )) + 1) / 2;
                    if(paramDepthVal != 0 && freq != 0){
                        chData[sample] *= mod * (paramDepthVal/100) + (1-(paramDepthVal/100));
                    }
                    
                    phase = phase + paramPhaseVal;
                }
            }
            
            time += t;
            
            if(time >= timePerOsc){
                time -= timePerOsc;
            }
        }
    }
}

//==============================================================================
bool TremoloAudioProcessor::hasEditor() const
{
    return true; // (change this to false if you choose to not supply an editor)
}

juce::AudioProcessorEditor* TremoloAudioProcessor::createEditor()
{
    return new TremoloAudioProcessorEditor (*this);
}

//==============================================================================
void TremoloAudioProcessor::getStateInformation (juce::MemoryBlock& destData)
{
    // You should use this method to store your parameters in the memory block.
    // You could do that either as raw data, or use the XML or ValueTree classes
    // as intermediaries to make it easy to save and load complex data.
    auto state = treeState.copyState();
    std::unique_ptr<juce::XmlElement> xml (state.createXml());
            copyXmlToBinary (*xml, destData);
}

void TremoloAudioProcessor::setStateInformation (const void* data, int sizeInBytes)
{
    // You should use this method to restore your parameters from this memory block,
    // whose contents will have been created by the getStateInformation() call.
    std::unique_ptr<juce::XmlElement> xmlState (getXmlFromBinary (data, sizeInBytes));
     
            if (xmlState.get() != nullptr)
                if (xmlState->hasTagName (treeState.state.getType()))
                    treeState.replaceState (juce::ValueTree::fromXml (*xmlState));
}

//==============================================================================
// This creates new instances of the plugin..
juce::AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new TremoloAudioProcessor();
}
