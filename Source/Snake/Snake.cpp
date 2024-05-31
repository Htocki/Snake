#include "Snake.hpp"

#include "SnakeState.hpp"

Snake::Snake()
  : m_state { new StandingState() }
  , m_isCollided { false }
{}

Snake::~Snake() {
  delete m_state;
}

bool Snake::IsCollided() const { return m_isCollided; }

void Snake::HandleInput(Input input) {
  SnakeState* state = m_state->HandleInput(*this, input);
  delete m_state;
  m_state = state;
}

void Snake::Update() {
  m_state->Update(*this);
}

void Snake::Render(sf::RenderWindow& window) {}

void Snake::CheckCollision() {}

void Snake::Reset() {
  delete m_state;
  m_state = new StandingState();
}