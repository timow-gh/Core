#ifndef CORECOLORRGBA_HPP
#define CORECOLORRGBA_HPP

#include "Core/Types/TArray.hpp"
#include "core_export.h"
#include <cmath>

namespace Core
{
class CORE_EXPORT ColorRGBA
{
    Core::TArray<float_t, 4> m_values;

  public:
    ColorRGBA() = default;
    ColorRGBA(float_t r, float_t g, float_t b, float_t a);
    explicit ColorRGBA(const Core::TArray<float_t, 4>& color);

    static ColorRGBA createDefaultColor();

    [[nodiscard]] const Core::TArray<float_t, 4>& getValues() const;
    void setValues(const Core::TArray<float_t, 4>& values);
};
} // namespace Core

#endif // CORECOLORRGBA_HPP