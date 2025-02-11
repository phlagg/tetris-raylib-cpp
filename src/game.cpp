#include "game.h"
#include "raylib.h"
#include "settings.h"
#include <stdlib.h>
#include <time.h>
#include <vector>

Game::Game()
    : m_grid(), m_blocks(GetAllBlocks()), m_currentBlock(GetRandomBlock()), m_nextBlock(GetRandomBlock()),
      gameOver(false), score(0), m_gridReference({ settings::outerPadding, settings::outerPadding }) {
  InitAudioDevice();
  music = LoadMusicStream("../assets/sounds/music.mp3");
  PlayMusicStream(music);
  m_rotateSound = LoadSound("../assets/sounds/rotate.mp3");
  m_clearSound = LoadSound("../assets/sounds/clear.mp3");
}

Game::~Game() {
  UnloadSound(m_rotateSound);
  UnloadSound(m_clearSound);
  UnloadMusicStream(music);
  CloseAudioDevice();
}

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
  m_grid.Draw();
  m_currentBlock.Draw(m_gridReference[0], m_gridReference[1]);
  switch(m_nextBlock.id) {
  case 3:
    m_nextBlock.Draw(255 * settings::scale, 290 * settings::scale);
    break;
  case 4:
    m_nextBlock.Draw(255 * settings::scale, 280 * settings::scale);
    break;
  default:
    m_nextBlock.Draw(270 * settings::scale, 270 * settings::scale);
    break;
  }
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
    UpdateScore(0, 1);
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
    if(m_grid.IsCellOutside(item.row, item.col)) {
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
    } else {
      PlaySound(m_rotateSound);
    }
  }
}

void Game::LockBlock() {
  std::vector<Position> tiles = m_currentBlock.GetCellPositions();
  for(Position item : tiles) {
    m_grid.grid[item.row][item.col] = m_currentBlock.id;
  }
  m_currentBlock = m_nextBlock;
  if(!BlockFits()) {
    gameOver = true;
  }
  m_nextBlock = GetRandomBlock();
  uint32_t rowsCleared = m_grid.ClearFullRows();
  if(rowsCleared) {
    PlaySound(m_clearSound);
    UpdateScore(rowsCleared, 0);
  }
}

bool Game::BlockFits() {
  std::vector<Position> tiles = m_currentBlock.GetCellPositions();
  for(Position item : tiles) {
    if(!m_grid.IsCellEmpty(item.row, item.col)) {
      return false;
    }
  }
  return true;
}

void Game::Reset() {
  m_grid.Initialize();
  m_blocks = GetAllBlocks();
  m_currentBlock = GetRandomBlock();
  m_nextBlock = GetRandomBlock();
  score = 0;
}

void Game::UpdateScore(uint32_t linesCleared, uint32_t moveDownPoints) {
  switch(linesCleared) {
  case 1:
    score += 100;
    break;
  case 2:
    score += 300;
    break;
  case 3:
    score += 500;
    break;
  default:
    break;
  }

  score += moveDownPoints;
}
