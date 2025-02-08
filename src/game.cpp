#include "game.h"
#include <stdlib.h>
#include <time.h>
#include <vector>
Game::Game()
    : grid(), m_blocks(GetAllBlocks()), m_currentBlock(GetRandomBlock()), m_nextBlock(GetRandomBlock()) {}

Block Game::GetRandomBlock() {
  if(m_blocks.empty()) {
    m_blocks = GetAllBlocks();
  }
  srand(time(NULL));
  int32_t randomIndex = rand() % m_blocks.size();
  Block block = m_blocks[randomIndex];
  m_blocks.erase(m_blocks.begin() + randomIndex);
  return block;
}

std::vector<Block> Game::GetAllBlocks() {
  return { IBlock(), JBlock(), LBlock(), OBlock(), SBlock(), TBlock(), ZBlock() };
}

void Game::Draw() {
  grid.Draw();
  m_currentBlock.Draw();
}

void Game::HandleInput() {
  int32_t keyPressed = GetKeyPressed();
  switch(keyPressed) {
  case KEY_LEFT:
    MoveBlockLeft();
    break;
  case KEY_RIGHT:
    MoveBlockRight();
    break;
  case KEY_DOWN:
    MoveBlockDown();
    break;
  case KEY_SPACE:
    RotateBlock();
    break;
  default:
    break;
  }
}

void Game::MoveBlockLeft() {
  m_currentBlock.Move(0, -1);
  if(IsBlockOutside()) {
    m_currentBlock.Move(0, 1);
  }
}
void Game::MoveBlockRight() {
  m_currentBlock.Move(0, 1);
  if(IsBlockOutside()) {
    m_currentBlock.Move(0, -1);
  }
}
void Game::MoveBlockDown() {
  m_currentBlock.Move(1, 0);
  if(IsBlockOutside()) {
    m_currentBlock.Move(-1, 0);
  }
}

bool Game::IsBlockOutside() {
  std::vector<Position> tiles = m_currentBlock.GetCellPositions();
  for(Position item : tiles) {
    if(grid.IsCellOutside(item.row, item.col)) {
      return true;
    }
  }
  return false;
}

void Game::RotateBlock() {
  m_currentBlock.Rotate();
  if(IsBlockOutside()) {
    m_currentBlock.UndoRotation();
  }
}
