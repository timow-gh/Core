#include "Core/Color/ColorTheme.hpp"

namespace Core
{
ColorTheme::ColorTheme()
    : m_backroundColor(
          ColorRGBA{0.101960784f, 0.109803922f, 0.125490196f, 1.0f})
    , m_pointColor(ColorRGBA{0.941176471f, 0.647058824f, 0.0f, 1.0f})
    , m_lineColor(ColorRGBA{0.941176471f, 0.647058824f, 0.0f, 1.0f})
    , m_triangleColor(ColorRGBA{0.811764706f, 0.458823529f, 0.0f, 1.0f})
{
}
const ColorRGBA& ColorTheme::getBackroundColor() const
{
    return m_backroundColor;
}
void ColorTheme::setBackroundColor(const ColorRGBA& backroundColor)
{
    m_backroundColor = backroundColor;
}
const ColorRGBA& ColorTheme::getPointColor() const
{
    return m_pointColor;
}
void ColorTheme::setPointColor(const ColorRGBA& pointColor)
{
    m_pointColor = pointColor;
}
const ColorRGBA& ColorTheme::getLineColor() const
{
    return m_lineColor;
}
void ColorTheme::setLineColor(const ColorRGBA& lineColor)
{
    m_lineColor = lineColor;
}
const ColorRGBA& ColorTheme::getTriangleColor() const
{
    return m_triangleColor;
}
void ColorTheme::setTriangleColor(const ColorRGBA& triangleColor)
{
    m_triangleColor = triangleColor;
}
} // namespace Core