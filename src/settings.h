#ifndef SETTINGS_H
#define SETTINGS_H
#include <cstdint>
#include <iostream>
#include <raylib.h>

namespace settings {

  // Window settings
  inline constexpr uint32_t scale = 2;
  inline constexpr uint32_t screenWidth = 300 * scale;
  inline constexpr uint32_t screenHeight = 600 * scale;
  inline constexpr uint32_t fps = 600;

  // Board settings
  inline constexpr uint32_t cellSize = 30 * scale;
  inline constexpr uint32_t padding = 1 * scale;
  inline constexpr uint32_t numCols = 10;
  inline constexpr uint32_t numRows = 20;

  // Game settings
  inline constexpr uint32_t COLOR_COUNT = 7;
  // Debug
  static void PrintTest() { std::cout << "Timer Elapsed" << std::endl; }
} // namespace settings

#endif /* SETTINGS_H */
