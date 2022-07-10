/*
  ==============================================================================

    CustomRotaryMiddleSliderLookAndFeel.h
    Created: 7 Jul 2022 2:43:33pm
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

class CustomRotaryMiddleSliderLookAndFeel : public juce::LookAndFeel_V4
{
    juce::Font getLabelFont(juce::Label& label) override;

    void drawRotarySlider (juce::Graphics& g, int x, int y, int width, int height, float sliderPos,
                           const float rotaryStartAngle, const float rotaryEndAngle, juce::Slider& slider) override;
    
};
