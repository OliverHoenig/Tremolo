/*
  ==============================================================================

    CustomToggleButtonLookAndFeel.h
    Created: 7 Jul 2022 2:44:35pm
    Author:  Oliver Hönig

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

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

class CustomToggleButtonLookAndFeel : public juce::LookAndFeel_V4
{
    void drawToggleButton (juce::Graphics& g, juce::ToggleButton& button, bool shouldDrawButtonAsHighlighted, bool shouldDrawButtonAsDown) override;
    
    void drawTickBox (juce::Graphics& g, juce::Component& component,
                                    float x, float y, float w, float h,
                                    const bool ticked,
                                    const bool isEnabled,
                                    const bool shouldDrawButtonAsHighlighted,
                                    const bool shouldDrawButtonAsDown)
    override;
};
