#include "blocks.cpp"
#include "grid.h"
#include "settings.h"
#include <raylib.h>
int main() {

  InitWindow(settings::screenWidth, settings::screenHeight, "Tetris-Raylib-Cpp");
  SetTargetFPS(settings::fps);
  SetExitKey(KEY_ESCAPE);

  Grid grid{};
  grid.Print();

  LBlock block;

  while(!WindowShouldClose()) {

    BeginDrawing();
    ClearBackground(colors::background);
    grid.Draw();
    block.Draw();
    EndDrawing();
  }

  CloseWindow();
}