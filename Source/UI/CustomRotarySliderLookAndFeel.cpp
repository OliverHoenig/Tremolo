/*
  ==============================================================================

    CustomRotarySliderLookAndFeel.cpp
    Created: 6 Jul 2022 10:54:46pm
    Author:  Oliver Hönig

  ==============================================================================
*/

#include "CustomRotarySliderLookAndFeel.h"


//CustomRotarySliderLookAndFeel::CustomRotarySliderLookAndFeel(){};

juce::Font CustomRotarySliderLookAndFeel::getLabelFont(juce::Label& label)
{
    return juce::Font(FONTSIZE_H1, juce::Font::plain);
}
void CustomRotarySliderLookAndFeel::drawRotarySlider (juce::Graphics& g, int x, int y, int width, int height, float sliderPos,
                                       const float rotaryStartAngle, const float rotaryEndAngle, juce::Slider& slider) 
{
    auto outline = juce::Colour(HEX_COLOUR_DIAL_BACK);
    auto fill_highlight    = juce::Colour(HEX_COLOUR_DIAL_FRONT_HIGHLIGHT);
    auto fill_backlight    = juce::Colour(HEX_COLOUR_DIAL_FRONT_BACKLIGHT);

    auto bounds = juce::Rectangle<int> (x, y, width, height).toFloat().reduced (10);

    auto radius = juce::jmin (bounds.getWidth(), bounds.getHeight()) / 2.0f;
    auto toAngle = rotaryStartAngle + sliderPos * (rotaryEndAngle - rotaryStartAngle);
    //auto lineW = juce::jmin (8.0f, radius * 0.5f);
    auto lineW = 3.0f;
    auto arcRadius = radius - lineW * 0.5f;

    juce::Path backgroundArc;
    backgroundArc.addCentredArc (bounds.getCentreX(),
                                 bounds.getCentreY(),
                                 arcRadius,
                                 arcRadius,
                                 0.0f,
                                 rotaryStartAngle,
                                 rotaryEndAngle,
                                 true);

    g.setColour (outline);
    g.strokePath (backgroundArc, juce::PathStrokeType (lineW,juce:: PathStrokeType::curved, juce::PathStrokeType::rounded));

    if (slider.isEnabled())
    {
        juce::Path valueArc;
        /*
        juce::DropShadower glow = juce::DropShadower(juce::DropShadow(juce::Colours::white, 10, juce::Point()));
        glow.setOwner(valueArc);
         */
        valueArc.addCentredArc (bounds.getCentreX(),
                                bounds.getCentreY(),
                                arcRadius,
                                arcRadius,
                                0.0f,
                                rotaryStartAngle,
                                toAngle,
                                true);

        g.setColour (fill_backlight);
        g.strokePath (valueArc, juce::PathStrokeType (lineW, juce::PathStrokeType::curved, juce::PathStrokeType::rounded));
        g.setColour (fill_highlight);
        g.setOpacity(sliderPos);
        g.strokePath (valueArc, juce::PathStrokeType (lineW, juce::PathStrokeType::curved, juce::PathStrokeType::rounded));
    }
}


