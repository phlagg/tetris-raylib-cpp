#include "grid.h"
#include "colors.h"
#include "settings.h"
#include <iostream>
Grid::Grid()
    : m_numCols(settings::numCols), m_numRows(settings::numRows), m_cellSize(settings::cellSize),
      m_cellPadding(settings::padding), m_colors(GetCellColors()) {
  Initialize();
}

void Grid::Initialize() {
  for(std::size_t row = 0; row < m_numRows; row++) {
    for(std::size_t column = 0; column < m_numCols; column++) {
      grid[row][column] = 0;
    }
  }
}

void Grid::Print() {
  for(std::size_t row = 0; row < m_numRows; row++) {
    for(std::size_t column = 0; column < m_numCols; column++) {
      std::cout << grid[row][column] << " ";
    }
    std::cout << std::endl;
  }
}

void Grid::Draw() {
  for(size_t row = 0; row < m_numRows; row++) {
    for(size_t col = 0; col < m_numCols; col++) {
      uint32_t cellValue = grid[row][col];
      DrawRectangle(col * m_cellSize + m_cellPadding, row * m_cellSize + m_cellPadding,
                    m_cellSize - m_cellPadding, m_cellSize - m_cellPadding, m_colors[cellValue]);
    }
  }
}

bool Grid::IsCellOutside(uint32_t row, uint32_t column) {
  if(row >= 0 && row < m_numRows && column >= 0 && column < m_numCols) {
    return false;
  }
  return true;
}
