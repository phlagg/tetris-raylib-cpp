#ifndef GAME_H
#define GAME_H

#include "board.h"
#include "tetrominoes.h"
#include <cstdint>
#include <string>

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
  Jay m_tetromino;
};

#endif
