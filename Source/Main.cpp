#include "Game.hpp"

int main() {
  Game game;
  while (game.IsRun()) {
    game.HandleInput();
    game.Update();
    game.Render();
    game.RestartClock();
  }
  return 0;
}