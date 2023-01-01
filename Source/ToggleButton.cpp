/*
  ==============================================================================

    ToggleButton.cpp
    Created: 30 Dec 2022 9:24:29pm
    Author:  CJ

  ==============================================================================
*/

#include "ToggleButton.h"

void LookAndFeel::drawToggleButton(juce::Graphics& g,
    juce::ToggleButton& toggleButton,
    bool shouldDrawButtonAsHighlighted,
    bool shouldDrawButtonAsDown)
{
    using namespace juce;

    if (auto* pb = dynamic_cast<PowerButton*>(&toggleButton))
    {
        Path powerButton;

        const auto bounds = toggleButton.getLocalBounds();

        auto size = jmin(bounds.getWidth(), bounds.getHeight()) - 6;
        auto r = bounds.withSizeKeepingCentre(size, size).toFloat();
        size -= 6;
        PathStrokeType pst(2.f, PathStrokeType::JointStyle::curved);

        auto color = toggleButton.getToggleState() ? Colours::dimgrey : Colours::cornflowerblue;

        g.strokePath(powerButton, pst);
        g.setColour(color);
        g.drawEllipse(r, 2);

        const juce::Image image = juce::ImageCache::getFromMemory(BinaryData::power_png, BinaryData::power_pngSize);
        g.drawImage(image, bounds.toFloat(), RectanglePlacement::stretchToFit);

        g.strokePath(powerButton, pst);

    }
    else if (auto* ab = dynamic_cast<AnalyzerButton*>(&toggleButton))
    {
        Path analyzerButton;

        const auto bounds = toggleButton.getLocalBounds();

        auto size = jmin(bounds.getWidth(), bounds.getHeight()) - 6;
        auto r = bounds.withSizeKeepingCentre(size, size).toFloat();
        size -= 6;
        PathStrokeType pst(2.f, PathStrokeType::JointStyle::curved);

        auto color = toggleButton.getToggleState() ? Colours::dimgrey : Colours::cornflowerblue;

        g.strokePath(analyzerButton, pst);
        g.setColour(color);
        g.drawEllipse(r, 2);

        const juce::Image image = juce::ImageCache::getFromMemory(BinaryData::chart_png, BinaryData::chart_pngSize);
        const juce::Rectangle imgBounds(bounds.getX()+10, bounds.getX()+10, bounds.getWidth()-20, bounds.getHeight()-20);
        g.drawImage(image, imgBounds.toFloat(), RectanglePlacement::stretchToFit);

        g.strokePath(analyzerButton, pst);
    }
}

