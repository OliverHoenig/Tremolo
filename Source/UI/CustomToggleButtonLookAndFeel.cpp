/*
  ==============================================================================

    CustomToggleButtonLookAndFeel.cpp
    Created: 7 Jul 2022 2:44:35pm
    Author:  Oliver Hönig

  ==============================================================================
*/

#include "CustomToggleButtonLookAndFeel.h"


void CustomToggleButtonLookAndFeel::drawToggleButton (juce::Graphics& g, juce::ToggleButton& button,
                                       bool shouldDrawButtonAsHighlighted, bool shouldDrawButtonAsDown)
{
    auto fontSize = juce::jmin (15.0f, (float) button.getHeight() * 0.75f);
    auto tickWidth = fontSize * 1.1f;
    
    drawTickBox (g, button, ((float) button.getWidth()/2.0 - tickWidth/2), ((float) button.getHeight() - tickWidth) * 0.5f,
                 tickWidth, tickWidth,
                 button.getToggleState(),
                 button.isEnabled(),
                 shouldDrawButtonAsHighlighted,
                 shouldDrawButtonAsDown);

    if (! button.isEnabled())
        g.setOpacity (0.5f);
}

void CustomToggleButtonLookAndFeel::drawTickBox (juce::Graphics& g, juce::Component& component,
                                                 float x, float y, float w, float h,
                                                 const bool ticked,
                                                 const bool isEnabled,
                                                 const bool shouldDrawButtonAsHighlighted,
                                                 const bool shouldDrawButtonAsDown)

{
    juce::ignoreUnused (isEnabled, shouldDrawButtonAsHighlighted, shouldDrawButtonAsDown);

    juce::Rectangle<float> tickBounds (x, y, w, h);

    g.setColour (juce::Colour(HEX_COLOUR_DIAL_BACK));
    g.drawEllipse(x,y,w,h,3);
    
    if (ticked)
    {
        g.setColour (juce::Colour(HEX_COLOUR_DIAL_FRONT_HIGHLIGHT));
        g.drawEllipse(x,y,w,h,3);
    }
}
