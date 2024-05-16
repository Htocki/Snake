#include "World.hpp"

#include <SFML/Graphics/Color.hpp>

World::World(sf::Vector2u windowSize) 
  : m_blockSize { 16 }
  , m_windowSize { windowSize }
{
  // Apple
  RespawnApple();
  m_apple.setFillColor(sf::Color::Red);
  m_apple.setRadius(8.f);

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

  int gridSize_x = m_windowSize.x / m_blockSize;
  int gridSize_y = m_windowSize.y / m_blockSize;

  if (snake.GetPosition().x <= 0 ||
      snake.GetPosition().y <= 0 ||
      snake.GetPosition().x >= gridSize_x - 1 ||
      snake.GetPosition().y >= gridSize_y - 1)
  {
    snake.Lose();
  }
}

void World::Render(sf::RenderWindow& window) {
  for (int i = 0; i < 4; ++i) {
    window.draw(m_bounds[i]);
  }
  window.draw(m_apple);
}