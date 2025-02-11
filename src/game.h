#ifndef GAME_H
#define GAME_H

#include "blocks.cpp"
#include "grid.h"
#include "raylib.h"
#include <array>
#include <vector>

class Game {
 public:
  Game();
  ~Game();
  void Draw();
  void MoveBlockDown();
  void HandleInput();
  bool gameOver;
  uint32_t score;
  Music music;

 private:
  Block GetRandomBlock();
  std::vector<Block> GetAllBlocks();
  void MoveBlockLeft();
  void MoveBlockRight();
  bool IsBlockOutside();
  void RotateBlock();
  void LockBlock();
  bool BlockFits();
  void Reset();
  void UpdateScore(uint32_t linesCleared, uint32_t moveDownPoints);

  Grid m_grid;
  std::vector<Block> m_blocks;
  Block m_currentBlock;
  Block m_nextBlock;
  std::array<uint32_t, 2> m_gridReference;
  Sound m_rotateSound;
  Sound m_clearSound;
};

#endif /* GAME_H */
