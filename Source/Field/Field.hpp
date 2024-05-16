#pragma once

#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Vector2.hpp>

class Field {
public:
  Field(sf::Vector2u size, int blockSize);
  ~Field();
  
  bool IsBorder(sf::Vector2i position) const;

  void Render(sf::RenderWindow& window);

private:
                 int m_blockSize;
        sf::Vector2u m_windowSize;
  sf::RectangleShape m_bounds[4];
};