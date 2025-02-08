#ifndef GRID_H
#define GRID_H
#include <cstdint>
#include <raylib.h>
#include <vector>

class Grid {

 public:
  Grid();
  void Initialize();
  void Print();
  void Draw();
  bool IsCellOutside(uint32_t row, uint32_t column);
  uint32_t grid[20][10];

 private:
  uint32_t m_numRows;
  uint32_t m_numCols;
  uint32_t m_cellSize;
  uint32_t m_cellPadding;
  std::vector<Color> m_colors;
};

#endif /* GRID_H */
