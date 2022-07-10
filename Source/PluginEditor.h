/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"

#include "UI/CustomRotarySlider.h"
#include "UI/CustomToggleButton.h"

#define HEX_COLOUR_BACKGROUND 0xff0E0E0E
#define HEX_COLOUR_FONT_LIGHT 0xffCCD3D2
#define HEX_COLOUR_FONT_DARK 0xff758086
#define HEX_COLOUR_DIAL_FRONT_HIGHLIGHT 0xff519D90
#define HEX_COLOUR_DIAL_FRONT_BACKLIGHT 0xff7A77B3
#define HEX_COLOUR_DIAL_BACK 0xff26272C

#define FONTSIZE_H1 18.0f
#define FONTSIZE_H2 15.0f
#define FONTSIZE_H3 13.0f

#define SIZE_ROTARYSILDER 130



//==============================================================================
/**
*/
class TremoloAudioProcessorEditor  : public juce::AudioProcessorEditor,
                                     public juce::Slider::Listener
{
public:
    TremoloAudioProcessorEditor (TremoloAudioProcessor&);
    ~TremoloAudioProcessorEditor() override;

    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;
    
    void sliderValueChanged (juce::Slider* slider) override;

private:
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    
    TremoloAudioProcessor& audioProcessor;
    CustomRotarySlider rateSlider;
    CustomRotarySlider phaseSlider;
    CustomRotarySlider depthSlider;
    CustomToggleButton bypassButton;
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (TremoloAudioProcessorEditor)
};
