#include "World.hpp"

#include <SFML/Graphics/Color.hpp>

World::World(sf::Vector2u windowSize) 
  : m_blockSize { 16 }
  , m_windowSize { windowSize }
  , m_field { windowSize, m_blockSize}
{
  // Apple
  RespawnApple();
  m_apple.setFillColor(sf::Color::Red);
  m_apple.setRadius(8.f);
}

World::~World() {}

int World::GetBlockSize() {
  return m_blockSize;
}

void World::RespawnApple() {
  int maxX = (m_windowSize.x / m_blockSize) - 2;
  int maxY = (m_windowSize.y / m_blockSize) - 2;
  m_item = sf::Vector2i(rand() % maxX + 1, rand() % maxY + 1);
  m_apple.setPosition(
    m_item.x * m_blockSize, 
    m_item.y * m_blockSize
  );
}

void World::Update(Snake& snake) {
  if (snake.GetPosition() == m_item) {
    snake.Extend();
    snake.IncreaseScore();
    RespawnApple();
  }

  if (m_field.IsBorder(snake.GetPosition())) {
    snake.Lose();
  }
}

void World::Render(sf::RenderWindow& window) {
  m_field.Render(window);
  window.draw(m_apple);
}