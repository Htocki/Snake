#pragma once

#include <vector>

#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Vector2.hpp>

#include "Input.hpp"

using Position = sf::Vector2u;
using SnakeSegments = std::vector<Position>;

class SnakeState;

class Snake {
public:
  Snake(Position position);
  ~Snake();

  Position GetPosition() { return m_snakeSegments[0]; }

  void MoveDown();
  void MoveLeft();
  void MoveRight();
  void MoveUp();
  void Reset();

  bool IsCollided() const;
  
  void HandleInput(Input input);
  void Update();
  void Render(sf::RenderWindow& window);

private:
  bool IsDownSideEmpty() const;
  bool IsLeftSideEmpty() const;
  bool IsRightSideEmpty() const;
  bool IsUpSideEmpty() const;
  
  SnakeState*   m_state;
  bool          m_isCollided;
  SnakeSegments m_snakeSegments;
  Position      m_beginPosition;
};