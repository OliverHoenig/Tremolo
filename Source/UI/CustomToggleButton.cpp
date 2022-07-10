/*
  ==============================================================================

    CustomToggleButton.cpp
    Created: 10 Jul 2022 3:28:01pm
    Author:  Oliver Hönig

  ==============================================================================
*/

#include <JuceHeader.h>
#include "CustomToggleButton.h"

//==============================================================================
CustomToggleButton::CustomToggleButton(std::string buttonName, std::string buttonID, juce::AudioProcessorValueTreeState& apvts)
{
    // In your constructor, you should add any child components, and
    // initialise any special settings that your component needs.
    button.setButtonText(buttonName);
    button.setLookAndFeel(&customToggleButtonLookAndFeel);
    buttonAttachment = std::make_unique<juce::AudioProcessorValueTreeState::ButtonAttachment>(apvts, buttonID, button);
    button.setToggleState(true, juce::NotificationType::dontSendNotification);
    addAndMakeVisible(button);

}

CustomToggleButton::~CustomToggleButton()
{
}

void CustomToggleButton::paint (juce::Graphics& g)
{
    /* This demo code just fills the component's background and
       draws some placeholder text to get you started.

       You should replace everything in this method with your own
       drawing code..
    */
}

void CustomToggleButton::resized()
{
    // This method is where you should set the bounds of any child
    // components that your component contains..
    button.setBounds(getWidth() / 2 - 50, 0, 100, 30);

}
