#pragma once

#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Vector2.hpp>

using Segments = std::vector<std::vector<sf::RectangleShape>>;

class Field {
public:
  Field(sf::Vector2u size, int blockSize);
  ~Field();
  
  bool IsBorder(sf::Vector2i position) const;

  void Render(sf::RenderWindow& window) const;

private:
  Segments m_segments;
};