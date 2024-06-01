#include "World.hpp"

#include <SFML/Graphics/Color.hpp>

World::World(sf::Vector2u windowSize) 
  : m_windowSize { windowSize }
{}

World::~World() {}

void World::Update(Snake& snake) {}

void World::Render(sf::RenderWindow& window) {
}