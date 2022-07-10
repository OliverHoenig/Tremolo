/*
  ==============================================================================

    CustomRotarySlider.cpp
    Created: 7 Jul 2022 8:11:12pm
    Author:  Oliver Hönig

  ==============================================================================
*/

#include <JuceHeader.h>
#include "CustomRotarySlider.h"

//==============================================================================
CustomRotarySlider::CustomRotarySlider(
                                       std::string sliderName, std::string sliderID,
                                       float min, float max, float stepSize,
                                       bool isMiddleSlider,
                                       std::string textboxSuffix,
                                       juce::AudioProcessorValueTreeState& apvts)
{
    // In your constructor, you should add any child components, and
    // initialise any special settings that your component needs.
    
    //==============Slider Attachment======================
    sliderAttachment = std::make_unique<juce::AudioProcessorValueTreeState::SliderAttachment>(apvts, sliderID, slider);
    
    //==============Slider Setup===========================
    //slider.setValue(defaultValue);
    slider.setRange (min, max, stepSize);
    slider.setTitle(sliderName);
    
    //==============Look And Feel==========================
    if(isMiddleSlider){
        slider.setLookAndFeel(&customRotaryMiddleSliderLookAndFeel);
    }else{
        slider.setLookAndFeel(&customRotarySliderLookAndFeel);
    }
    slider.getLookAndFeel().setColour(juce::Slider::ColourIds::textBoxOutlineColourId, juce::Colour::fromFloatRGBA (0.0f, 0.0f, 0.0f, 0.0f));
    slider.setSliderStyle (juce::Slider::SliderStyle::RotaryHorizontalVerticalDrag);
    
    //==============Text Box===============================
    //slider.setTextBoxStyle(juce::Slider::TextEntryBoxPosition::TextBoxBelow, false, 50, 20);
    slider.setTextBoxStyle(juce::Slider::TextEntryBoxPosition::TextBoxAbove, false, 100, 20);
    slider.setTextValueSuffix(textboxSuffix);
    
    //==============Lable==============
    label.setFont(juce::Font(FONTSIZE_H3, juce::Font::plain));
    label.setColour (juce::Label::textColourId, juce::Colour(HEX_COLOUR_FONT_DARK));
    label.setText(sliderName, juce::dontSendNotification);
    label.attachToComponent(&slider, false);
    label.setJustificationType(juce::Justification::centred);
    
    //==============MakeVisible============================
    addAndMakeVisible(slider);

}

CustomRotarySlider::~CustomRotarySlider()
{
}

void CustomRotarySlider::paint (juce::Graphics& g)
{
    /* This demo code just fills the component's background and
       draws some placeholder text to get you started.

       You should replace everything in this method with your own
       drawing code..
    */

    //g.fillAll(juce::Colours::black);
}

void CustomRotarySlider::resized()
{
    // This method is where you should set the bounds of any child
    // components that your component contains..

    slider.setBounds(getWidth() / 2 - SIZE_ROTARYSILDER/2, 18, SIZE_ROTARYSILDER, SIZE_ROTARYSILDER);

}

