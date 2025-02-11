#include "game.h"
#include <stdlib.h>
#include <time.h>
#include <vector>
Game::Game()
    : grid(), m_blocks(GetAllBlocks()), m_currentBlock(GetRandomBlock()), m_nextBlock(GetRandomBlock()),
      gameOver(false) {}

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
  if(gameOver && keyPressed != 0) {
    gameOver = false;
    Reset();
  }
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
  if(!gameOver) {
    m_currentBlock.Move(0, -1);
    if(IsBlockOutside() || !BlockFits()) {
      m_currentBlock.Move(0, 1);
    }
  }
}
void Game::MoveBlockRight() {
  if(!gameOver) {
    m_currentBlock.Move(0, 1);
    if(IsBlockOutside() || !BlockFits()) {
      m_currentBlock.Move(0, -1);
    }
  }
}
void Game::MoveBlockDown() {
  if(!gameOver) {
    m_currentBlock.Move(1, 0);
    if(IsBlockOutside() || !BlockFits()) {
      m_currentBlock.Move(-1, 0);
      LockBlock();
    }
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
  if(!gameOver) {
    m_currentBlock.Rotate();
    if(IsBlockOutside()) {
      m_currentBlock.UndoRotation();
    }
  }
}

void Game::LockBlock() {
  std::vector<Position> tiles = m_currentBlock.GetCellPositions();
  for(Position item : tiles) {
    grid.grid[item.row][item.col] = m_currentBlock.id;
  }
  m_currentBlock = m_nextBlock;
  if(!BlockFits()) {
    gameOver = true;
  }
  m_nextBlock = GetRandomBlock();
  grid.ClearFullRows();
}

bool Game::BlockFits() {
  std::vector<Position> tiles = m_currentBlock.GetCellPositions();
  for(Position item : tiles) {
    if(!grid.IsCellEmpty(item.row, item.col)) {
      return false;
    }
  }
  return true;
}

void Game::Reset() {
  grid.Initialize();
  m_blocks = GetAllBlocks();
  m_currentBlock = GetRandomBlock();
  m_nextBlock = GetRandomBlock();
}
