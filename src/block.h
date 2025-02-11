#ifndef BLOCK_H
#define BLOCK_H

#include "position.h"
#include "raylib.h"
#include <cstdint>
#include <map>
#include <vector>

class Block {
 public:
  Block();
  void Draw();
  void Move(int32_t rows, int32_t columns);
  std::vector<Position> GetCellPositions();
  void Rotate();
  void UndoRotation();
  uint32_t id;
  std::map<uint32_t, std::vector<Position>> cells;

 private:
  uint32_t m_cellSize;
  uint32_t m_rotationState;
  uint32_t m_cellPadding;
  std::vector<Color> m_colors;
  uint32_t m_rowOffset;
  uint32_t m_columnOffset;
};

#endif /* BLOCK_H */