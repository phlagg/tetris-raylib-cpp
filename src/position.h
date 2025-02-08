#ifndef POSITION_H
#define POSITION_H
#include <cstdint>
class Position {
 public:
  Position(uint32_t row, uint32_t col);
  uint32_t row;
  uint32_t col;
};

inline Position::Position(uint32_t row, uint32_t col) : row(row), col(col) {}

#endif /* POSITION_H */
