#ifndef BOARD_H
#define BOARD_H

#include "raylibCpp.h"
#include "vec2.h"
#include <cstdint>
#include <vector>

class Board {
 public:
  Board(Vec2<uint32_t> screenPos, Vec2<uint32_t> widthHeight, uint32_t cellSize, uint32_t padding);
  ~Board();

  void SetCell(Vec2<uint32_t> pos, Color color);
  void DrawCell(Vec2<uint32_t> pos) const;
  void DrawCell(Vec2<uint32_t> pos, Color color) const;
  void DrawBorder() const;
  void Draw() const;
  bool CellExists(Vec2<uint32_t> pos) const;
  uint32_t GetWidth() const;
  uint32_t GetHeight() const;

 private:
  class Cell {
   public:
    Cell();
    ~Cell();
    void SetColor(Color color);
    void Remove();
    bool Exists() const;
    Color GetColor() const;

   private:
    bool m_exists;
    Color m_color;
  };

 private:
  std::vector<Cell> m_cells;
  const uint32_t m_width;
  const uint32_t m_height;
  const uint32_t m_cellSize;
  const uint32_t m_padding;
  Vec2<uint32_t> m_screenPos;
};

#endif /* BOARD_H */
