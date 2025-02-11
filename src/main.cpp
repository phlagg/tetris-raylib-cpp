#include "colors.h"
#include "game.h"
#include "settings.h"
#include <raylib.h>

double lastUpdateTime = 0;

bool EventTriggered(double interval) {
  double currentTime = GetTime();
  if(currentTime - lastUpdateTime >= interval) {
    lastUpdateTime = currentTime;
    return true;
  }
  return false;
}

int main() {

  InitWindow(settings::screenWidth, settings::screenHeight, "Tetris-Raylib-Cpp");
  SetTargetFPS(settings::fps);
  SetExitKey(KEY_ESCAPE);

  Game game;

  while(!WindowShouldClose()) {

    game.HandleInput();
    if(EventTriggered(0.02)) {
      game.MoveBlockDown();
    }
    BeginDrawing();
    ClearBackground(background);
    game.Draw();
    EndDrawing();
  }

  CloseWindow();
}