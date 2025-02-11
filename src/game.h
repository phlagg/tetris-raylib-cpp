#ifndef GAME_H
#define GAME_H

#include "blocks.cpp"
#include "grid.h"
#include <vector>

class Game {
 public:
  Game();
  Block GetRandomBlock();
  std::vector<Block> GetAllBlocks();
  void Draw();
  void HandleInput();
  void MoveBlockLeft();
  void MoveBlockRight();
  void MoveBlockDown();
  Grid grid;
  bool gameOver;

 private:
  bool IsBlockOutside();
  void RotateBlock();
  void LockBlock();
  bool BlockFits();
  void Reset();
  std::vector<Block> m_blocks;
  Block m_currentBlock;
  Block m_nextBlock;
};

#endif /* GAME_H */
