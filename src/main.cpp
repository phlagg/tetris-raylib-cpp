#include "game.h"
#include "settings.h"
#include <raylib.h>

int main() {

  InitWindow(settings::screenWidth, settings::screenHeight, "Tetris-Raylib-Cpp");
  SetTargetFPS(settings::fps);
  SetExitKey(KEY_ESCAPE);

  Game game;

  while(!WindowShouldClose()) {

    game.HandleInput();
    BeginDrawing();
    ClearBackground(background);
    game.Draw();
    EndDrawing();
  }

  CloseWindow();
}