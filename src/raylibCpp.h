#ifndef RAYLIBCPP_H
#define RAYLIBCPP_H
#include "raylib.h"
#include "vec2.h"
#include <cstdint>

namespace raycpp {

  void DrawRectangle(Vec2<uint32_t> pos, Vec2<uint32_t>,
                     Color color); // Draw a color-filled rectangle

  void DrawRectangleLinesEx(Vec2<uint32_t> pos, Vec2<uint32_t> widthHeight, uint32_t lineThickness,
                            Color color); // Draw rectangle outline

}

#endif // !RAYLIBCPP_H
