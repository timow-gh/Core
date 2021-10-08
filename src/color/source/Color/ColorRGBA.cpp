#include "Core/Color/ColorRGBA.hpp"

namespace Core
{
ColorRGBA::ColorRGBA(float_t r, float_t g, float_t b, float_t a)
    : m_values({r, g, b, a})
{
}
ColorRGBA::ColorRGBA(const Core::TArray<float_t, 4>& color) : m_values(color)
{
}
const Core::TArray<float_t, 4>& ColorRGBA::getValues() const
{
    return m_values;
}
void ColorRGBA::setValues(const Core::TArray<float_t, 4>& values)
{
    m_values = values;
}
ColorRGBA ColorRGBA::createDefaultColor()
{
    return ColorRGBA{0.941176471f, 0.647058824f, 0.0f, 1.0f};
}
} // namespace Core