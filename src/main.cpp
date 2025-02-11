#include "colors.h"
#include "game.h"
#include "settings.h"
#include <iostream>
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
  float uiScale = settings::scale;
  InitWindow(settings::screenWidth, settings::screenHeight, "Tetris-Raylib-Cpp");
  SetTargetFPS(settings::fps);
  SetExitKey(KEY_ESCAPE);

  Font font = LoadFontEx("../assets/font/monogram.ttf", 64, 0, 0);

  Game game;

  while(!WindowShouldClose()) {
    UpdateMusicStream(game.music);
    game.HandleInput();
    if(EventTriggered(0.2)) {
      game.MoveBlockDown();
    }
    BeginDrawing();
    ClearBackground(background);
    if(game.gameOver) {
      DrawTextEx(font, "Game Over", { 320 * uiScale, 450 * uiScale }, 38 * uiScale, 2 * uiScale, WHITE);
    }
    DrawTextEx(font, "Score", { 365 * uiScale, 15 * uiScale }, 38 * uiScale, 2 * uiScale, WHITE);
    DrawRectangleRounded({ 320 * uiScale, 55 * uiScale, 170 * uiScale, 60 * uiScale }, 0.3 * uiScale,
                         6 * uiScale, lightBlue);
    char scoreText[10];
    sprintf(scoreText, "%d", game.score);
    Vector2 textSize = MeasureTextEx(font, scoreText, 38 * uiScale, 2 * uiScale);
    DrawTextEx(font, scoreText, { 320 * uiScale + (170 * uiScale - textSize.x) / 2, 65 * uiScale },
               38 * uiScale, 2 * uiScale, WHITE);

    DrawTextEx(font, "Next", { 370 * uiScale, 175 * uiScale }, 38 * uiScale, 2 * uiScale, WHITE);
    DrawRectangleRounded({ 320 * uiScale, 215 * uiScale, 170 * uiScale, 180 * uiScale }, 0.3, 6 * uiScale,
                         lightBlue);
    game.Draw();
    EndDrawing();
  }

  CloseWindow();
}
