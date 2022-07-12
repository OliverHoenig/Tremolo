/*
  ==============================================================================

    CustomRotarySlider.h
    Created: 7 Jul 2022 8:11:12pm
    Author:  Oliver Hönig

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "CustomRotarySliderLookAndFeel.h"
#include "CustomRotaryMiddleSliderLookAndFeel.h"

//==============================================================================
/*
*/
class CustomRotarySlider  : public juce::Component
{
public:
    CustomRotarySlider(
                       std::string sliderName, std::string sliderID,
                       float min, float max, float stepSize,
                       bool isMiddleSlider,
                       std::string textboxSuffix,
                       juce::AudioProcessorValueTreeState& apvts);
    ~CustomRotarySlider() override;

    void paint (juce::Graphics&) override;
    void resized() override;

private:
    
    juce::Slider slider;
    CustomRotarySliderLookAndFeel customRotarySliderLookAndFeel;
    CustomRotaryMiddleSliderLookAndFeel customRotaryMiddleSliderLookAndFeel;

    juce::Label label;
    
    std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment> sliderAttachment;
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (CustomRotarySlider)
};
