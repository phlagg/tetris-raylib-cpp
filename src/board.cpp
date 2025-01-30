#include "board.h"
#include "raylib.h"
#include "vec2.h"
#include <assert.h>
#include <cstdint>

Board::Board(Vec2<uint32_t> screenPos, Vec2<uint32_t> widthHeight,
             uint32_t cellSize, uint32_t padding)
    : m_screenPos(screenPos), m_width(widthHeight.GetX()),
      m_height(widthHeight.GetY()), m_cellSize(cellSize), m_padding(padding) {
  assert(m_width > 0 &&
         m_height >
             0); // If assertion triggers: the width or height is smaller than 1
  assert(cellSize >
         0); // If assertion triggers: the cell size is smaller than 1
  m_cells.resize(m_width * m_height);
}

Board::~Board() {}

void Board::SetCell(Vec2<uint32_t> pos, Color color) {
  assert(pos.GetX() >= 0 && pos.GetY() >= 0 && pos.GetX() < m_width &&
         pos.GetY() <
             m_height); // If assertion triggers: x or y is off the board
  m_cells[pos.GetX() + m_width * pos.GetY()].SetColor(color);
}

void Board::DrawCell(Vec2<uint32_t> pos) const {
  assert(pos.GetX() >= 0 && pos.GetY() >= 0 && pos.GetX() < m_width &&
         pos.GetY() <
             m_height); // If assertion triggers: x or y is off the board
  Color cellColor = m_cells[pos.GetX() + m_width * pos.GetY()].GetColor();
  Vec2<uint32_t> topLeft = m_screenPos + m_padding + (pos * m_cellSize);
  DrawRectangle(topLeft.GetX(), topLeft.GetY(), m_cellSize - m_padding,
                m_cellSize - m_padding, cellColor);
}

void Board::Draw() const {
  for (size_t iY = 0; iY < m_height; iY++) {
    for (size_t iX = 0; iX < m_width; iX++) {
      DrawCell({static_cast<unsigned int>(iX), static_cast<unsigned int>(iY)});
    }
  }
}

Board::Cell::Cell() : m_exists(false), m_color(RAYWHITE) {}

void Board::Cell::SetColor(Color color) {
  m_color = color;
  m_exists = true;
}

Color Board::Cell::GetColor() const { return m_color; }

void Board::Cell::Remove() { m_exists = false; }
Board::Cell::~Cell() {}
