#ifndef VEC2_H
#define VEC2_H

#include <cstdint>
#include <sys/types.h>
template <typename T> class Vec2 {
public:
  Vec2() = default;
  Vec2(T x, T y) : m_x(x), m_y(y) {};

  T GetX() const { return m_x; };
  T GetY() const { return m_y; };

  void SetX(T x_in) { m_x = x_in; };
  void SetY(T y_in) { m_y = y_in; };

public:
  bool operator==(const Vec2 &rhs) const {
    return (m_x == rhs.m_x && m_y == rhs.m_y);
  }
  bool operator!=(const Vec2 &rhs) const {
    return !(m_x == rhs.m_x && m_y == rhs.m_y);
  }
  Vec2 operator+(const Vec2 &rhs) const {
    return {m_x + rhs.m_x, m_y + rhs.m_y};
  }
  Vec2 operator+(const uint32_t rhs) const { return {m_x + rhs, m_y + rhs}; }
  Vec2 &operator+=(const Vec2 &rhs) { return {*this = *this + rhs}; }
  Vec2 operator-(const Vec2 &rhs) const {
    return {m_x - rhs.m_x, m_y - rhs.m_y};
  }
  Vec2 &operator-=(const Vec2 &rhs) { return {*this = *this - rhs}; }
  Vec2 operator*(const Vec2 &rhs) const {
    return {m_x * rhs.m_x, m_y * rhs.m_y};
  }
  Vec2 operator*(const uint32_t rhs) const { return {m_x * rhs, m_y * rhs}; }
  Vec2 &operator*=(const Vec2 &rhs) const { return {*this = *this * rhs}; }

private:
  T m_x;
  T m_y;
};

#endif // VEC2_H
