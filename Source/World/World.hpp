#pragma once

#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Vector2.hpp>

#include "Field.hpp"
#include "Snake.hpp"

class World {
public:
  World(sf::Vector2u windowSize);
  ~World();

  int GetBlockSize();

  void RespawnApple();
  
  void Update(Snake& player);
  void Render(sf::RenderWindow& window);

private:
     sf::Vector2u m_windowSize;
     sf::Vector2i m_item;
              int m_blockSize;
  sf::CircleShape m_apple;
            Field m_field;
};