#include "Field.hpp"

Field::Field(sf::Vector2u windowSize, int blockSize) 
  : m_windowSize { windowSize }
  , m_blockSize { blockSize }
{
  // Bounds
  for (int i = 0; i < 4; ++i) {
    m_bounds[i].setFillColor(sf::Color(sf::Color::Green));
    if (!((i + 1) % 2)) {
      m_bounds[i].setSize(sf::Vector2f(m_windowSize.x, m_blockSize));
    } else {
      m_bounds[i].setSize(sf::Vector2f(m_blockSize, m_windowSize.y)); 
    }

    if (i < 2) {
      m_bounds[i].setPosition(0, 0);
    } else {
      m_bounds[i].setOrigin(m_bounds[i].getSize());
      m_bounds[i].setPosition(sf::Vector2f(m_windowSize));
    }
  }
}

Field::~Field() {}

bool Field::IsBorder(sf::Vector2i position) const {
  sf::Vector2u gridSize {  // Размер сетки в ячейках.
    m_windowSize.x / m_blockSize,
    m_windowSize.y / m_blockSize
  };
  return position.x <= 0 ||
      position.y <= 0 ||
      position.x >= gridSize.x - 1 ||
      position.y >= gridSize.y - 1;
}

void Field::Render(sf::RenderWindow& window) {
  for (int i = 0; i < 4; ++i) {
    window.draw(m_bounds[i]);
  }
}