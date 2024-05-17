#pragma once

#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Vector2.hpp>

#include "Apple.hpp"
#include "Field.hpp"
#include "Snake.hpp"

class World {
public:
  World(sf::Vector2u windowSize);
  ~World();

  int GetBlockSize();
  
  void Update(Snake& player);
  void Render(sf::RenderWindow& window);

private:
  sf::Vector2u m_windowSize;
           int m_blockSize;
         Field m_field;
         Apple m_apple;
};