#include "game.h"
#include <assert.h>
#include <raylib.h>

Game::Game(uint32_t width, uint32_t height, std::string title) {
    assert(!IsWindowReady());  // If assertion triggers then window is already open
    InitWindow(width, height, title.c_str());
}

Game::~Game() noexcept {
    assert(IsWindowReady());
    CloseWindow();
}

bool Game::GameShouldClose() const {
    return WindowShouldClose();
}
void Game::Tick() {
    BeginDrawing();
    Update();
    Draw();
    EndDrawing();
}
void Game::Draw() {
    ClearBackground(RAYWHITE);
}
void Game::Update() {}
