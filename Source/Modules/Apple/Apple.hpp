#pragma once

#include <SFML/System/Vector2.hpp>

#include "Field.hpp"

using Position = sf::Vector2u;

class Apple {
public:
  Apple(const Field& field);
  const Position& GetPosition() const;
  void            Respawn(const Field& field);

private:
  Position m_position;
};