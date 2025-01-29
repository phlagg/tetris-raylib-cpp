#include <math.h>
#include <cstdint>
#include "game.h"

#include "raylib-cpp.hpp"
#include "raymath.h"

uint32_t screenWidth = 1920;
uint32_t screenHeight = 1080;

int main() {
  SetExitKey(KEY_ESCAPE);
  SetTargetFPS(1200);

  Game game{screenWidth, screenHeight, "Tetris Raylib"};

  while (!game.GameShouldClose()) {
    game.Tick();
  }

  return 0;
}
