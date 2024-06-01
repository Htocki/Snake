#include "SnakeState.hpp"

#include <iostream>

using Position = sf::Vector2u;

// Moving Down State

SnakeState* MovingDownState::HandleInput(Snake& snake, Input input) {
  if      (input == Input::KbLeft)  { return new MovingLeftState(); }
  else if (input == Input::KbRight) { return new MovingRightState(); }
  else if (snake.IsCollided())      { return new StandingState(); }
  else                              { return new MovingDownState(); }
}

void MovingDownState::Update(Snake& snake) {
  std::cout << "Down: Position: x = " << snake.GetPosition().x << " y = " << snake.GetPosition().y << std::endl;
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
  std::cout << "Left: Position: x = " << snake.GetPosition().x << " y = " << snake.GetPosition().y << std::endl;
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
  std::cout << "Right: Position: x = " << snake.GetPosition().x << " y = " << snake.GetPosition().y << std::endl;
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
  std::cout << "Up: Position: x = " << snake.GetPosition().x << " y = " << snake.GetPosition().y << std::endl;
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

void StandingState::Update(Snake& snake) {
  std::cout << "Standing: Position: x = " << snake.GetPosition().x << " y = " << snake.GetPosition().y << std::endl;
}