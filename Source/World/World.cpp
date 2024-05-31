#include "World.hpp"

#include <SFML/Graphics/Color.hpp>

World::World(sf::Vector2u windowSize) 
  : m_blockSize { 16 }
  , m_windowSize { windowSize }
  , m_field { windowSize, m_blockSize }
  , m_apple { windowSize, m_blockSize }
{}

World::~World() {}

int World::GetBlockSize() {
  return m_blockSize;
}

void World::Update(Snake& snake) {}

void World::Render(sf::RenderWindow& window) {
  m_field.Render(window);
  m_apple.Render(window);
}