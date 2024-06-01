#pragma once

#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Vector2.hpp>

#include "Apple.hpp"
#include "Snake.hpp"

class World {
public:
  World(sf::Vector2u windowSize);
  ~World();
  
  void Update(Snake& player);
  void Render(sf::RenderWindow& window);

private:
  sf::Vector2u m_windowSize;
};