#include "SnakeState.hpp"

using Position = sf::Vector2u;

// Moving Down State

SnakeState* MovingDownState::HandleInput(Snake& snake, Input input) {
  if      (input == Input::KbLeft)  { return new MovingLeftState(); }
  else if (input == Input::KbRight) { return new MovingRightState(); }
  else if (snake.IsCollided())      { return new StandingState(); }
  else                              { return new MovingDownState(); }
}

void MovingDownState::Update(Snake& snake) {
  snake.MoveDown();  
}

// Moving Left State

SnakeState* MovingLeftState::HandleInput(Snake& snake, Input input) {
  if      (input == Input::KbDown)  { return new MovingDownState(); }
  else if (input == Input::KbUp)    { return new MovingUpState(); }
  else if (snake.IsCollided())      { return new StandingState(); }
  else                              { return new MovingLeftState(); }
}

void MovingLeftState::Update(Snake& snake) {
  snake.MoveLeft();
}

// Moving Right State

SnakeState* MovingRightState::HandleInput(Snake& snake, Input input) {
  if      (input == Input::KbDown)  { return new MovingDownState(); }
  else if (input == Input::KbUp)    { return new MovingUpState(); }
  else if (snake.IsCollided())      { return new StandingState(); }
  else                              { return new MovingRightState(); }
}

void MovingRightState::Update(Snake& snake) {
  snake.MoveRight();
}

// Moving Up State

SnakeState* MovingUpState::HandleInput(Snake& snake, Input input) {
  if      (input == Input::KbLeft)  { return new MovingLeftState(); }
  else if (input == Input::KbRight) { return new MovingRightState(); }
  else if (snake.IsCollided())      { return new StandingState(); }
  else                              { return new MovingUpState(); }
}

void MovingUpState::Update(Snake& snake) {
  snake.MoveUp();
}

// Standing State

SnakeState* StandingState::HandleInput(Snake& snake, Input input) {
  if      (input == Input::KbDown)  { return new MovingDownState(); }
  else if (input == Input::KbLeft)  { return new MovingLeftState(); }
  else if (input == Input::KbRight) { return new MovingRightState(); }
  else if (input == Input::KbUp)    { return new MovingUpState(); }
  else                              { return new StandingState(); }
}

void StandingState::Update(Snake& snake) {}