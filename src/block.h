#ifndef BLOCK_H
#define BLOCK_H

#include "colors.h"
#include "position.h"
#include <cstdint>
#include <map>
#include <vector>

class Block {
 public:
  Block();
  void Draw();
  uint32_t id;
  std::map<uint32_t, std::vector<Position>> cells;

 private:
  uint32_t m_cellSize;
  uint32_t m_rotationState;
  uint32_t m_cellPadding;
  std::vector<Color> m_colors;
};

#endif /* BLOCK_H */