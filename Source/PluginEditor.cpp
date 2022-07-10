/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
TremoloAudioProcessorEditor::TremoloAudioProcessorEditor (TremoloAudioProcessor& p)
    : AudioProcessorEditor (&p), audioProcessor (p),
        rateSlider(RATE_NAME, RATE_ID,
                   0.0f, 20.0f, 0.01f,
                   false,
                   " Hz",
                   audioProcessor.treeState),
        phaseSlider(PHASE_NAME, PHASE_ID,
                    -180.0f, 180.0f, 10.0f,
                    true,
                    " °",
                    audioProcessor.treeState),
        depthSlider(DEPTH_NAME, DEPTH_ID,
                    0.0f, 100.0f, 1.0f,
                    false,
                    " %",
                    audioProcessor.treeState),
        bypassButton(BYPASS_NAME, BYPASS_ID,
                     audioProcessor.treeState)
{
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    
    addAndMakeVisible(rateSlider);;
    addAndMakeVisible(phaseSlider);
    addAndMakeVisible(depthSlider);
    addAndMakeVisible(bypassButton);

    setSize (200, 580);
}

TremoloAudioProcessorEditor::~TremoloAudioProcessorEditor()
{
}

//==============================================================================
void TremoloAudioProcessorEditor::paint (juce::Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    //g.fillAll (juce::Colours::red);
    g.fillAll (juce::Colour(HEX_COLOUR_BACKGROUND));
    g.setColour (juce::Colours::white);
    g.setFont (15.0f);
}

void TremoloAudioProcessorEditor::resized()
{
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..
    
    rateSlider.setBounds(
                         getWidth() / 2 - SIZE_ROTARYSILDER/2,
                         35,
                         SIZE_ROTARYSILDER,
                         SIZE_ROTARYSILDER);
    phaseSlider.setBounds(
                          getWidth() / 2 - SIZE_ROTARYSILDER/2,
                          195,
                          SIZE_ROTARYSILDER,
                          SIZE_ROTARYSILDER);
    depthSlider.setBounds(
                          getWidth() / 2 - SIZE_ROTARYSILDER/2,
                          355,
                          SIZE_ROTARYSILDER,
                          SIZE_ROTARYSILDER);
    

    bypassButton.setBounds(getWidth() / 2 - 50, 530, 100, 30);
    
}

void TremoloAudioProcessorEditor::sliderValueChanged(juce::Slider *slider)
{
}
 
