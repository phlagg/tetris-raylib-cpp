#include "game.h"
#include <assert.h>
#include <cstdint>
#include <raylib.h>

Game::Game(uint32_t width, uint32_t height, uint32_t fps, std::string title)
    : m_board({200, 200}, {10, 20}, 15, 2) {
  assert(
      !GetWindowHandle()); // If assertion triggers then window is already open
  SetTargetFPS(fps);
  InitWindow(width, height, title.c_str());

  for (size_t iY = 0; iY < 20; iY++) {
    for (size_t iX = 0; iX < 10; iX++) {
      m_board.SetCell(
          {static_cast<unsigned int>(iX), static_cast<unsigned int>(iY)}, RED);
    }
  }
}

Game::~Game() noexcept {
  assert(
      GetWindowHandle()); // If assertion trigger then Window is already closed
  CloseWindow();
}

bool Game::GameShouldClose() const { return WindowShouldClose(); }
void Game::Tick() {
  BeginDrawing();
  Update();
  Draw();
  EndDrawing();
}
void Game::Draw() {
  ClearBackground(BLACK);
  m_board.Draw();
}
void Game::Update() {}
