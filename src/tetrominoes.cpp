#include "tetrominoes.h"
#include "vec2.h"

Tetromino::Tetromino(const bool* shape, uint32_t dimension, Color color, const Board& board)
    : m_shape(shape), m_dimension(dimension), m_color(color),
      m_boardPos((board.GetWidth()) / 2 - (dimension / 2), 0), m_board(board) {}

void Tetromino::Draw() const {
  for(size_t y = 0; y < m_dimension; y++) {
    for(size_t x = 0; x < m_dimension; x++) {
      bool cell = m_shape[y * m_dimension + x];
      if(cell) {
        m_board.DrawCell(m_boardPos
                             + Vec2<uint32_t>{ static_cast<unsigned int>(x), static_cast<unsigned int>(y) },
                         m_color);
      }
    }
  }
}
