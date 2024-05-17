#pragma once

#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Vector2.hpp>

class Apple {
public:
  Apple(const sf::Vector2u& windowSize, int blockSize);
  void Respawn();
  const sf::Vector2i& GetPosition() const;
  void Render(sf::RenderWindow& window) const;

private:
     sf::Vector2u m_windowSize;
              int m_blockSize;
  sf::CircleShape m_apple;
     sf::Vector2i m_gridPosition;
};