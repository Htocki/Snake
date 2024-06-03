#pragma once

#include <SFML/System/Vector2.hpp>

#include "Apple.hpp"
#include "Data.hpp"
#include "Input.hpp"
#include "Snake.hpp"

using Size = sf::Vector2u;

class World {
  void UpdateData();

public:
  World(const Size& size);
  const Data& GetData() const;
  void        HandleInput(Input input);
  void        Update();

private:
  Field m_field;
  Apple m_apple;
  Snake m_snake;
  Data  m_data;
};