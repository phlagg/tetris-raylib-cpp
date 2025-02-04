#include "game.h"
#include "settings.h"

#include <math.h>

int main() {
  SetExitKey(KEY_ESCAPE);
  SetTargetFPS(1200);

  Game game{ settings::screenWidth, settings::screenHeight, settings::fps, "Tetris Raylib" };

  while(!game.GameShouldClose()) {
    game.Tick();
  }

  return 0;
}
