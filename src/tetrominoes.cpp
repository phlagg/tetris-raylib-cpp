#include "tetrominoes.h"
#include "vec2.h"

Tetromino::Tetromino(const bool* shape, uint32_t dimension, Color color, const Board& board)
    : m_shape(shape), m_dimension(dimension), m_color(color),
      m_boardPos((board.GetWidth()) / 2 - (dimension / 2), 0), m_board(board),
      m_currentRotation(Rotation::UP) {}

void Tetromino::Draw() const {
  for(std::size_t y = 0; y < m_dimension; y++) {
    for(std::size_t x = 0; x < m_dimension; x++) {

      bool cell = false;
      switch(m_currentRotation) {
      case Tetromino::Rotation::UP:
        cell = m_shape[y * m_dimension + x];
        break;
      case Tetromino::Rotation::RIGHT:
        cell = m_shape[m_dimension * (m_dimension - 1) - m_dimension * x + y];
        break;
      case Tetromino::Rotation::DOWN:
        cell = m_shape[(m_dimension * m_dimension - 1) - m_dimension * y - x];
        break;
      case Tetromino::Rotation::LEFT:
        cell = m_shape[m_dimension - 1 + m_dimension * x - y];
        break;
      default:
        break;
      }

      if(cell) {
        m_board.DrawCell(m_boardPos + Vec2<uint32_t>{ uint32_t(x), uint32_t(y) }, m_color);
      }
    }
  }
}

void Tetromino::RotateClockwise() { m_currentRotation = Rotation((int(m_currentRotation) + 1) % 4); }

void Tetromino::RotateCounterClockwise() {
  m_currentRotation
      = (m_currentRotation == Rotation::UP) ? Rotation::LEFT : Rotation((int(m_currentRotation) - 1));
}
