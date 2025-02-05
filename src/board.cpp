#include "board.h"
#include "raylib.h"
#include "vec2.h"
#include <assert.h>
#include <cstdint>

Board::Board(Vec2<uint32_t> screenPos, Vec2<uint32_t> widthHeight, uint32_t cellSize, uint32_t padding)
    : m_screenPos(screenPos), m_width(widthHeight.GetX()), m_height(widthHeight.GetY()), m_cellSize(cellSize),
      m_padding(padding) {

  // If assertion triggers: the width or height is smaller than 1
  assert(m_width > 0 && m_height > 0);
  // If assertion triggers: the cell size is smaller than 1
  assert(cellSize > 0);
  m_cells.resize(m_width * m_height);
}

Board::~Board() {}

void Board::SetCell(Vec2<uint32_t> pos, Color color) {
  // If assertion triggers: x or y is off the board
  assert(pos.GetX() >= 0 && pos.GetY() >= 0 && pos.GetX() < m_width && pos.GetY() < m_height);
  m_cells[pos.GetX() + m_width * pos.GetY()].SetColor(color);
}

void Board::DrawCell(Vec2<uint32_t> pos) const {
  Color color = m_cells[pos.GetX() + m_width * pos.GetY()].GetColor();
  DrawCell(pos, color);
}

void Board::DrawCell(Vec2<uint32_t> pos, Color color) const {
  // If assertion triggers: x or y is off the board
  assert(pos.GetX() >= 0 && pos.GetY() >= 0 && pos.GetX() < m_width && pos.GetY() < m_height);
  Vec2<uint32_t> topLeft = m_screenPos + m_padding + (pos * m_cellSize);
  raycpp::DrawRectangle(topLeft, Vec2<uint32_t>{ m_cellSize, m_cellSize } - m_padding, color);
}

void Board::DrawBorder() const {
  raycpp::DrawRectangleLinesEx(m_screenPos - (m_cellSize / 2),
                               Vec2{ m_width * m_cellSize, m_height * m_cellSize } + m_cellSize + m_padding,
                               m_cellSize / 2, WHITE);
}

void Board::Draw() const {
  for(std::size_t iY = 0; iY < m_height; iY++) {
    for(std::size_t iX = 0; iX < m_width; iX++) {
      if(CellExists({ uint32_t(iX), uint32_t(iY) })) {
        DrawCell({ uint32_t(iX), uint32_t(iY) });
      }
    }
  }
  DrawBorder();
}

bool Board::CellExists(Vec2<uint32_t> pos) const {
  return m_cells[pos.GetY() * m_width + pos.GetX()].Exists();
}

uint32_t Board::GetWidth() const { return m_width; }

uint32_t Board::GetHeight() const { return m_height; }

Board::Cell::Cell() : m_exists(false), m_color(RAYWHITE) {}

void Board::Cell::SetColor(Color color) {
  m_color = color;
  m_exists = true;
}

Color Board::Cell::GetColor() const { return m_color; }

void Board::Cell::Remove() { m_exists = false; }
bool Board::Cell::Exists() const { return m_exists; }
Board::Cell::~Cell() {}
