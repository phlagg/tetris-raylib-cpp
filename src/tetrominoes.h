#ifndef TETROMINOES_H
#define TETROMINOES_H

#include "board.h"
#include "raylibCpp.h"
#include "vec2.h"
#include <assert.h>

class Tetromino {
 public:
  Tetromino(const bool* shape, uint32_t dimension, Color color, const Board& board);
  void Draw() const;

 private:
  Vec2<uint32_t> m_boardPos;
  const Color m_color;
  const bool* m_shape;
  const uint32_t m_dimension;
  const Board& m_board;
};

class Straight : public Tetromino {
 public:
  Straight(const Board& board) : Tetromino(m_shape, m_dimension, m_color, board) {
    static_assert(sizeof(m_shape) / sizeof(bool) == m_dimension * m_dimension);
  };

 private:
  // clang-format off
  static constexpr bool m_shape[] = {
    0, 0, 0, 0, 
    1, 1, 1, 1, 
    0, 0, 0, 0, 
    0, 0, 0, 0,
  }; // clang-format on
  static constexpr uint32_t m_dimension = 4;
  static constexpr Color m_color = SKYBLUE;
};

class Square : public Tetromino {
 public:
  Square(const Board& board) : Tetromino(m_shape, m_dimension, m_color, board) {
    static_assert(sizeof(m_shape) / sizeof(bool) == m_dimension * m_dimension);
  };

 private:
  // clang-format off
  static constexpr bool m_shape[] = {
    1, 1, 
    1, 1, 
  }; // clang-format on
  static constexpr uint32_t m_dimension = 2;
  static constexpr Color m_color = YELLOW;
};

class Tee : public Tetromino {
 public:
  Tee(const Board& board) : Tetromino(m_shape, m_dimension, m_color, board) {
    static_assert(sizeof(m_shape) / sizeof(bool) == m_dimension * m_dimension);
  };

 private:
  // clang-format off
  static constexpr bool m_shape[] = {
    0, 1, 0,  
    1, 1, 1,  
    0, 0, 0,  
  }; // clang-format on
  static constexpr uint32_t m_dimension = 3;
  static constexpr Color m_color = MAGENTA;
};

class Jay : public Tetromino {
 public:
  Jay(const Board& board) : Tetromino(m_shape, m_dimension, m_color, board) {
    static_assert(sizeof(m_shape) / sizeof(bool) == m_dimension * m_dimension);
  };

 private:
  // clang-format off
  static constexpr bool m_shape[] = {
    1, 0, 0,
    1, 1, 1,
    0, 0, 0,
  }; // clang-format on
  static constexpr uint32_t m_dimension = 3;
  static constexpr Color m_color = DARKBLUE;
};

class El : public Tetromino {
 public:
  El(const Board& board) : Tetromino(m_shape, m_dimension, m_color, board) {
    static_assert(sizeof(m_shape) / sizeof(bool) == m_dimension * m_dimension);
  };

 private:
  // clang-format off
  static constexpr bool m_shape[] = {
    0, 0, 1,
    1, 1, 1,
    0, 0, 0,
  }; // clang-format on
  static constexpr uint32_t m_dimension = 3;
  static constexpr Color m_color = ORANGE;
};

class SkewS : public Tetromino {
 public:
  SkewS(const Board& board) : Tetromino(m_shape, m_dimension, m_color, board) {
    static_assert(sizeof(m_shape) / sizeof(bool) == m_dimension * m_dimension);
  };

 private:
  // clang-format off
  static constexpr bool m_shape[] = {
    0, 1, 1,
    1, 1, 0,
    0, 0, 0,
  }; // clang-format on
  static constexpr uint32_t m_dimension = 3;
  static constexpr Color m_color = GREEN;
};

class SkewZ : public Tetromino {
 public:
  SkewZ(const Board& board) : Tetromino(m_shape, m_dimension, m_color, board) {
    static_assert(sizeof(m_shape) / sizeof(bool) == m_dimension * m_dimension);
  };

 private:
  // clang-format off
  static constexpr bool m_shape[] = {
    1, 1, 0,
    0, 1, 1,
    0, 0, 0,
  }; // clang-format on
  static constexpr uint32_t m_dimension = 3;
  static constexpr Color m_color = RED;
};

#endif /* TETROMINOES_H */
