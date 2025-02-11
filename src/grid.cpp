#include "grid.h"
#include "colors.h"
#include "settings.h"
#include <iostream>

Grid::Grid()
    : m_numCols(settings::numCols), m_numRows(settings::numRows), m_cellSize(settings::cellSize),
      m_cellPadding(settings::padding), m_outerPadding(settings::outerPadding), m_colors(GetCellColors()) {
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
      DrawRectangle(col * m_cellSize + m_cellPadding + m_outerPadding,
                    row * m_cellSize + m_cellPadding + m_outerPadding, m_cellSize - m_cellPadding,
                    m_cellSize - m_cellPadding, m_colors[cellValue]);
    }
  }
}

bool Grid::IsCellOutside(uint32_t row, uint32_t column) {
  if(row >= 0 && row < m_numRows && column >= 0 && column < m_numCols) {
    return false;
  }
  return true;
}

bool Grid::IsCellEmpty(uint32_t row, uint32_t column) {
  if(grid[row][column] == 0) {
    return true;
  }
  return false;
}

uint32_t Grid::ClearFullRows() {
  uint32_t completed = 0;
  for(ssize_t row = m_numRows - 1; row >= 0; --row) {
    if(IsRowFull(row)) {
      ClearRow(row);
      completed++;
    } else if(completed > 0) {
      MoveRowDown(row, completed);
    }
  }
  return completed;
}

bool Grid::IsRowFull(uint32_t row) {
  for(size_t column = 0; column < m_numCols; column++) {
    if(grid[row][column] == 0) {
      return false;
    }
  }
  return true;
}

void Grid::ClearRow(uint32_t row) {
  for(size_t column = 0; column < m_numCols; column++) {
    grid[row][column] = 0;
  }
}

void Grid::MoveRowDown(uint32_t row, uint32_t numRows) {
  for(size_t column = 0; column < m_numCols; column++) {
    grid[row + numRows][column] = grid[row][column];
    grid[row][column] = 0;
  }
}
