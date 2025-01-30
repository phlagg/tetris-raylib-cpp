#include <math.h>
#include <cstdint>
#include "game.h"

#include "raylib-cpp.hpp"
#include "raymath.h"

uint32_t screenWidth = 800;
uint32_t screenHeight = 600;

int main() {
  SetExitKey(KEY_ESCAPE);
  SetTargetFPS(1200);

  Game game{screenWidth, screenHeight, 1200, "Tetris Raylib"};

  while (!game.GameShouldClose()) {
    game.Tick();
  }

  return 0;
}
