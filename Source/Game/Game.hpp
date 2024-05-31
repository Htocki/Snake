#pragma once

#include <SFML/System/Clock.hpp>

#include "Input.hpp"
#include "Snake.hpp"
#include "Textbox.hpp"
#include "Window.hpp"
#include "World.hpp"

class Game {
public:
  Game();
  ~Game();

  void HandleInput();
  void Update();
  void Render();
  void RestartClock();

  bool IsRun() const;
  
  sf::Time GetElapsed() const;

private:
     Window m_window;
  sf::Clock m_clock;
   sf::Time m_elapsed;
      World m_world;
      Snake m_snake;
    Textbox m_textbox;
};