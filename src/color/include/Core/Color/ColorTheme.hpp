#ifndef CORE_COLORTHEME_HPP
#define CORE_COLORTHEME_HPP

#include "ColorRGBA.hpp"
#include "core_export.h"

namespace Core
{
class CORE_EXPORT ColorTheme
{
    ColorRGBA m_backroundColor;
    ColorRGBA m_pointColor;
    ColorRGBA m_lineColor;
    ColorRGBA m_triangleColor;

  public:
    ColorTheme();

    [[nodiscard]] const ColorRGBA& getBackroundColor() const;
    void setBackroundColor(const ColorRGBA& backroundColor);
    [[nodiscard]] const ColorRGBA& getPointColor() const;
    void setPointColor(const ColorRGBA& pointColor);
    [[nodiscard]] const ColorRGBA& getLineColor() const;
    void setLineColor(const ColorRGBA& lineColor);
    [[nodiscard]] const ColorRGBA& getTriangleColor() const;
    void setTriangleColor(const ColorRGBA& triangleColor);
};
} // namespace Core

#endif // CORE_COLORTHEME_HPP
