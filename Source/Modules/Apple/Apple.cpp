#include "Apple.hpp"

Apple::Apple(const sf::Vector2u& windowSize, int blockSize) 
  : m_blockSize { blockSize }
  , m_windowSize { windowSize }
{
  Respawn();
  m_apple.setFillColor(sf::Color::Red);
  m_apple.setRadius(8.f);
}

void Apple::Respawn() {
  // Размеры поля в ячейках без учета границ.
  sf::Vector2u max {
    (m_windowSize.x / m_blockSize) - 2,
    (m_windowSize.y / m_blockSize) - 2
  };
  m_gridPosition.x = rand() % max.x + 1;
  m_gridPosition.y = rand() % max.y + 1;
  m_apple.setPosition(
    m_gridPosition.x * m_blockSize, 
    m_gridPosition.y * m_blockSize
  );
}

const sf::Vector2i& Apple::GetPosition() const {
  return m_gridPosition;
}

void Apple::Render(sf::RenderWindow& window) const {
  window.draw(m_apple);
}