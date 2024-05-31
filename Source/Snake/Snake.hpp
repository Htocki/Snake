#pragma once

#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Vector2.hpp>

#include "Input.hpp"

class SnakeState;

class Snake {
public:
  Snake();
  ~Snake();

  bool IsCollided() const;
  void HandleInput(Input input);
  void Update();
  void Render(sf::RenderWindow& window);
  void Reset();

private:
  void CheckCollision();
  
  SnakeState* m_state;
  bool        m_isCollided;
};