#include "Snake.hpp"

#include "SnakeState.hpp"

Snake::Snake(Position position)
  : m_state { new StandingState() }
  , m_isCollided { false }
  , m_beginPosition { position }
{
  m_snakeSegments.push_back(position);
}

Snake::~Snake() {
  delete m_state;
}

void Snake::MoveDown() {
  if (IsDownSideEmpty()) {
    m_snakeSegments[0].y += 1;
  }
}

void Snake::MoveLeft() {
  if (IsLeftSideEmpty()) {
    m_snakeSegments[0].x -= 1;
  }
}

void Snake::MoveRight() {
  if (IsRightSideEmpty()) {
    m_snakeSegments[0].x += 1;
  }
}

void Snake::MoveUp() {
  if (IsUpSideEmpty()) {
    m_snakeSegments[0].y -= 1;
  }
}

void Snake::Reset() {
  delete m_state;
  m_state = new StandingState();
  m_snakeSegments.clear();
  m_snakeSegments.push_back(m_beginPosition);
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

bool Snake::IsDownSideEmpty() const {
  return true;
}

bool Snake::IsLeftSideEmpty() const {
  return true;
}

bool Snake::IsRightSideEmpty() const {
  return true;
}

bool Snake::IsUpSideEmpty() const {
  return true;
}
