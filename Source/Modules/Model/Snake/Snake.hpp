#pragma once

#include <vector>

#include <SFML/System/Vector2.hpp>

#include "Field.hpp"
#include "Input.hpp"

using Position = sf::Vector2u;
using SnakeSegments = std::vector<Position>;

class SnakeState;

class Snake {
  bool IsBorder(const Position& position) const;

public:
  Snake(Field& field);
  ~Snake();

  void HandleInput(Input input);
  void MoveDown();
  void MoveLeft();
  void MoveRight();
  void MoveUp();
  void Respawn();
  void SetField(Field& field);
  void Update();

private:
  Field&         m_field;
  SnakeSegments  m_segments;
  SnakeState*    m_state;
};