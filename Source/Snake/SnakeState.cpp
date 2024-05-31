#include "SnakeState.hpp"

#include "Snake.hpp"

// Moving Down State

MovingDownState::MovingDownState() {}

void MovingDownState::HandleInput(Snake& snake, Input input) {
  if      (input == Input::KbLeft)  { snake.m_state = &SnakeState::movingLeft; }
  else if (input == Input::KbRight) { snake.m_state = &SnakeState::movingRight; }
  else if (snake.IsCollided())      { snake.m_state = &SnakeState::standing; }
  else                              { snake.m_state = &SnakeState::movingDown; }
}

void MovingDownState::Update(Snake& snake) {}

// Moving Left State

MovingLeftState::MovingLeftState() {}

void MovingLeftState::HandleInput(Snake& snake, Input input) {
  if      (input == Input::KbDown)  { snake.m_state = &SnakeState::movingDown; }
  else if (input == Input::KbUp)    { snake.m_state = &SnakeState::movingUp; }
  else if (snake.IsCollided())      { snake.m_state = &SnakeState::standing; }
  else                              { snake.m_state = &SnakeState::movingLeft; }
}

void MovingLeftState::Update(Snake& snake) {}

// Moving Right State

MovingRightState::MovingRightState() {}

void MovingRightState::HandleInput(Snake& snake, Input input) {
  if      (input == Input::KbDown)  { snake.m_state = &SnakeState::movingDown; }
  else if (input == Input::KbUp)    { snake.m_state = &SnakeState::movingUp; }
  else if (snake.IsCollided())      { snake.m_state = &SnakeState::standing; }
  else                              { snake.m_state = &SnakeState::movingRight; }
}

void MovingRightState::Update(Snake& snake) {}

// Moving Up State

MovingUpState::MovingUpState() {}

void MovingUpState::HandleInput(Snake& snake, Input input) {
  if      (input == Input::KbLeft)  { snake.m_state = &SnakeState::movingLeft; }
  else if (input == Input::KbRight) { snake.m_state = &SnakeState::movingRight; }
  else if (snake.IsCollided())      { snake.m_state = &SnakeState::standing; }
  else                              { snake.m_state = &SnakeState::movingUp; }
}

void MovingUpState::Update(Snake& snake) {}

// Standing State

StandingState::StandingState() {}

void StandingState::HandleInput(Snake& snake, Input input) {
  if      (input == Input::KbDown)  { snake.m_state = &SnakeState::movingDown; }
  else if (input == Input::KbLeft)  { snake.m_state = &SnakeState::movingLeft; }
  else if (input == Input::KbRight) { snake.m_state = &SnakeState::movingRight; }
  else if (input == Input::KbUp)    { snake.m_state = &SnakeState::movingUp; }
  else                              { snake.m_state = &SnakeState::standing; }
}

void StandingState::Update(Snake& snake) {}