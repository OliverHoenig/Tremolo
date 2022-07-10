/*
  ==============================================================================

    CustomRotaryMiddleSliderLookAndFeel.cpp
    Created: 7 Jul 2022 2:43:33pm
    Author:  Oliver Hönig

  ==============================================================================
*/

#include "CustomRotaryMiddleSliderLookAndFeel.h"


juce::Font CustomRotaryMiddleSliderLookAndFeel::getLabelFont(juce::Label& label)
{
    return juce::Font(FONTSIZE_H1, juce::Font::plain);
}
void CustomRotaryMiddleSliderLookAndFeel::drawRotarySlider (juce::Graphics& g, int x, int y, int width, int height, float sliderPos,
                                       const float rotaryStartAngle, const float rotaryEndAngle, juce::Slider& slider)
{
    auto outline = juce::Colour(HEX_COLOUR_DIAL_BACK);
    auto fill_hightlight    = juce::Colour(HEX_COLOUR_DIAL_FRONT_HIGHLIGHT);
    auto fill_backlight    = juce::Colour(HEX_COLOUR_DIAL_FRONT_BACKLIGHT);

    auto bounds = juce::Rectangle<int> (x, y, width, height).toFloat().reduced (10);

    auto radius = juce::jmin (bounds.getWidth(), bounds.getHeight()) / 2.0f;
    //auto toAngle = rotaryStartAngle + sliderPos * (rotaryEndAngle - rotaryStartAngle);
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

    if (slider.isEnabled() && slider.getValue() > 0)  {
                juce::Path valueArc;
                valueArc.addCentredArc(bounds.getCentreX(), bounds.getCentreY(), arcRadius, arcRadius, 0.0f, 0, (0.0 + (sliderPos - 0.5)* (2.51327-0) / (1.0 - 0.5)) , true);
                std::cout << sliderPos << std::endl;
                g.setColour(fill_backlight);
                g.strokePath(valueArc, juce::PathStrokeType (lineW, juce::PathStrokeType::curved, juce::PathStrokeType::rounded));
                g.setColour(fill_hightlight);
                g.setOpacity(sliderPos);
                g.strokePath(valueArc, juce::PathStrokeType (lineW, juce::PathStrokeType::curved, juce::PathStrokeType::rounded));
            } else if (slider.isEnabled() && slider.getValue() < 0) {
                juce::Path valueArc2;
                valueArc2.addCentredArc(bounds.getCentreX(), bounds.getCentreY(), arcRadius, arcRadius, 0.0f, 0, (0.0 + (sliderPos - 0.5)* (-2.51327-0) / (0.0 - 0.5)), true);
                std::cout << sliderPos << std::endl;
                g.setColour(fill_backlight);
                g.strokePath(valueArc2, juce::PathStrokeType (lineW, juce::PathStrokeType::curved, juce::PathStrokeType::rounded));
                g.setColour(fill_hightlight);
                g.setOpacity(sliderPos);
                g.strokePath(valueArc2, juce::PathStrokeType (lineW, juce::PathStrokeType::curved, juce::PathStrokeType::rounded));
            }
    
    //setColour(juce::Slider::ColourIds::textBoxOutlineColourId, juce::Colour(HEX_COLOUR_BACKGROUND));
    /*
    auto thumbWidth = lineW * 2.0f;
    juce::Point<float> thumbPoint (bounds.getCentreX() + arcRadius * std::cos (toAngle - juce::MathConstants<float>::halfPi),
                             bounds.getCentreY() + arcRadius * std::sin (toAngle - juce::MathConstants<float>::halfPi));

    g.setColour (slider.findColour (juce::Slider::thumbColourId));
    g.fillEllipse (juce::Rectangle<float> (thumbWidth, thumbWidth).withCentre (thumbPoint));
    */
}

