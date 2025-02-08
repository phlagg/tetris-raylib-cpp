#include "block.h"
#include "raylib.h"
#include "settings.h"
#include <vector>

Block::Block()
    : m_cellSize(settings::cellSize), m_rotationState(0), m_cellPadding(settings::padding),
      m_colors(GetCellColors()), m_rowOffset(0), m_columnOffset(0) {}

void Block::Draw() {
  std::vector<Position> tiles = GetCellPositions();
  for(Position item : tiles) {
    DrawRectangle(item.col * m_cellSize + m_cellPadding, item.row * m_cellSize + m_cellPadding,
                  m_cellSize - m_cellPadding, m_cellSize - m_cellPadding, m_colors[id]);
  }
}

void Block::Move(int32_t rows, int32_t columns) {
  m_rowOffset += rows;
  m_columnOffset += columns;
}

std::vector<Position> Block::GetCellPositions() {
  std::vector<Position> tiles = cells[m_rotationState];
  std::vector<Position> movedTiles;
  for(Position item : tiles) {
    Position newPos = Position(item.row + m_rowOffset, item.col + m_columnOffset);
    movedTiles.push_back(newPos);
  }
  return movedTiles;
}

void Block::Rotate() { m_rotationState = (m_rotationState + 1) % cells.size(); }

void Block::UndoRotation() { m_rotationState = (m_rotationState - 1) % cells.size(); }
