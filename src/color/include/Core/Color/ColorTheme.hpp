#ifndef CORE_COLORTHEME_HPP
#define CORE_COLORTHEME_HPP

#include "ColorRGBA.hpp"
#include <Core/Utils/Compiler.hpp>
#include <color_export.h>

namespace Core
{
class COLOR_EXPORT ColorTheme
{
    ColorRGBA m_backroundColor;
    ColorRGBA m_pointColor;
    ColorRGBA m_lineColor;
    ColorRGBA m_triangleColor;

  public:
    ColorTheme();

    NODISCARD const ColorRGBA& getBackroundColor() const;
    void setBackroundColor(const ColorRGBA& backroundColor);
    NODISCARD const ColorRGBA& getPointColor() const;
    void setPointColor(const ColorRGBA& pointColor);
    NODISCARD const ColorRGBA& getLineColor() const;
    void setLineColor(const ColorRGBA& lineColor);
    NODISCARD const ColorRGBA& getTriangleColor() const;
    void setTriangleColor(const ColorRGBA& triangleColor);
};
} // namespace Core

#endif // CORE_COLORTHEME_HPP
