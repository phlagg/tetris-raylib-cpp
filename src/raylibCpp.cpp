#include "raylibCpp.h"
#include "raylib.h"
#include <assert.h>
#include <cstdint>
void raycpp::DrawRectangle(Vec2<uint32_t> pos, Vec2<uint32_t> widthHeight, Color color) {
  assert(pos.GetX() >= 0 && pos.GetY() >= 0 && pos.GetX() < GetScreenWidth()
         && pos.GetY() < GetScreenHeight());
  DrawRectangle(pos.GetX(), pos.GetY(), widthHeight.GetX(), widthHeight.GetY(), color);

} // Draw a color-filled rectangle

void raycpp::DrawRectangleLinesEx(Vec2<uint32_t> pos, Vec2<uint32_t> widthHeight, uint32_t lineThickness,
                                  Color color) {
  assert(pos.GetX() >= 0 && pos.GetY() >= 0 && pos.GetX() < GetScreenWidth()
         && pos.GetY() < GetScreenHeight());
  assert(lineThickness > 0);
  DrawRectangleLinesEx(
      { (float)pos.GetX(), (float)pos.GetY(), (float)widthHeight.GetX(), (float)widthHeight.GetY() },
      lineThickness, color);
}