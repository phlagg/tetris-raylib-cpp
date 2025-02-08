#include "block.h"
#include "raylib.h"
#include "settings.h"
#include <vector>

Block::Block()
    : m_cellSize(settings::cellSize), m_rotationState(0), m_cellPadding(settings::padding),
      m_colors(GetCellColors()) {}

void Block::Draw() {
  std::vector<Position> tiles = cells[m_rotationState];
  for(Position item : tiles) {
    DrawRectangle(item.col * m_cellSize + m_cellPadding, item.row * m_cellSize + m_cellPadding,
                  m_cellSize - m_cellPadding, m_cellSize - m_cellPadding, m_colors[id]);
  }
}
