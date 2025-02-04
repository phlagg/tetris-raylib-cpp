#ifndef SETTINGS_H
#define SETTINGS_H

#include "vec2.h"
#include <cstdint>

namespace settings {

  // Window settings
  inline constexpr uint32_t scale = 2;
  inline constexpr uint32_t screenWidth = 800 * scale;
  inline constexpr uint32_t screenHeight = 600 * scale;
  inline constexpr uint32_t fps = 1200;

  // Board settings
  inline constexpr uint32_t cellSize = 23 * scale;
  inline constexpr uint32_t padding = 2 * scale;
  inline constexpr Vec2<uint32_t> boardPosition{ 250 * scale, 70 * scale };
  inline constexpr Vec2<uint32_t> boardWidthHeight{ 10, 20 };

} // namespace settings

#endif /* SETTINGS_H */
