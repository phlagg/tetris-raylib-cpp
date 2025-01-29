#ifndef GAME_H
#define GAME_H

#include <cstdint>
#include <string>

class Game {
public:
  Game(uint32_t width, uint32_t height, std::string title);
  ~Game() noexcept;
  bool GameShouldClose() const;
  void Tick();

private:
  void Draw();
  void Update();
};

#endif
