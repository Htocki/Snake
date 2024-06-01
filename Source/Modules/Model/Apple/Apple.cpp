#include "Apple.hpp"

#include <cstdlib>
#include <ctime>

Apple::Apple(const Field& field) {
  Respawn(field);
}

void Apple::Respawn(const Field& field) {
  std::srand(std::time(nullptr));
  do {
    m_position.x = std::rand() % field.GetSize().x;
    m_position.y = std::rand() % field.GetSize().y;
  } while (field.GetState(m_position) != SegmentState::Empty);
}

const Position& Apple::GetPosition() const {
  return m_position;
}