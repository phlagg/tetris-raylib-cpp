#include "game.h"
#include "settings.h"
#include <assert.h>
#include <cstdint>
#include <raylib.h>

Game::Game(uint32_t width, uint32_t height, uint32_t fps, std::string title)
    : m_board(settings::boardPosition, settings::boardWidthHeight, settings::cellSize, settings::padding),
      m_tetromino(m_board) {

  // If assertion triggers then window is already open
  assert(!GetWindowHandle());

  SetTargetFPS(fps);
  InitWindow(width, height, title.c_str());
}

Game::~Game() noexcept {
  assert(GetWindowHandle()); // If assertion trigger then Window is already closed
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
  m_tetromino.Draw();
}
void Game::Update() {
  if(IsKeyPressed(KEY_E) || IsKeyPressed(KEY_SPACE)) {
    m_tetromino.RotateClockwise();
  }
  if(IsKeyPressed(KEY_Q)) {
    m_tetromino.RotateCounterClockwise();
  }
}
