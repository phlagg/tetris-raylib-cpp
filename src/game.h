#ifndef GAME_H
#define GAME_H

#include <cstdint>
#include <string>
#include "board.h"

class Game {
  public:
    Game(uint32_t width, uint32_t height, uint32_t fps, std::string title);
    Game(const Game& other) = delete;
    Game& operator=(const Game& other) = delete;
    ~Game() noexcept;
    bool GameShouldClose() const;
    void Tick();

  private:
    void Draw();
    void Update();

    Board m_board;
};

#endif
