/*
  ==============================================================================

    CustomToggleButton.h
    Created: 10 Jul 2022 3:28:01pm
    Author:  Oliver Hönig

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "CustomToggleButtonLookAndFeel.h"

//==============================================================================
/*
*/
class CustomToggleButton  : public juce::Component
{
public:
    CustomToggleButton(std::string buttonName, std::string buttonID, juce::AudioProcessorValueTreeState& apvts);
    ~CustomToggleButton() override;

    void paint (juce::Graphics&) override;
    void resized() override;

private:
    
    CustomToggleButtonLookAndFeel customToggleButtonLookAndFeel;
    
    juce::ToggleButton button;
    std::unique_ptr<juce::AudioProcessorValueTreeState::ButtonAttachment> buttonAttachment;
    
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (CustomToggleButton)
};
