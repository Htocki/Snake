#include "Apple.hpp"

#include <cstdlib>
#include <ctime>

#include <SFML/System/Vector2.hpp>

using Position = sf::Vector2u;

Apple::Apple(Field& field) 
  : m_field { field }
{}

void Apple::Respawn() {
  Position position;
  std::srand(std::time(nullptr));
  do {
    position.x = std::rand() % m_field.GetSize().x;
    position.y = std::rand() % m_field.GetSize().y;
  } while (m_field.GetState(position) != SegmentState::Empty);
  m_field.SetState(position, SegmentState::Apple);
}