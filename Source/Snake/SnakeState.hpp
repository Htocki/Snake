#pragma once

#include "Input.hpp"
#include "Snake.hpp"

class SnakeState {
public:
  virtual ~SnakeState() {}
  virtual SnakeState* HandleInput(Snake& snake, Input input) = 0;
  virtual void Update(Snake& snake) = 0;
};

class MovingDownState : public SnakeState {
public:
  MovingDownState() {}
  virtual SnakeState* HandleInput(Snake& snake, Input input) override;
  virtual void Update(Snake& snake) override;
};

class MovingLeftState : public SnakeState {
public:
  MovingLeftState() {}
  virtual SnakeState* HandleInput(Snake& snake, Input input) override;
  virtual void Update(Snake& snake) override;
};

class MovingRightState : public SnakeState {
public:
  MovingRightState() {}
  virtual SnakeState* HandleInput(Snake& snake, Input input) override;
  virtual void Update(Snake& snake) override;
};

class MovingUpState : public SnakeState {
public:
  MovingUpState() {}
  virtual SnakeState* HandleInput(Snake& snake, Input input) override;
  virtual void Update(Snake& snake) override;
};

class StandingState : public SnakeState {
public:
  StandingState() {}
  virtual SnakeState* HandleInput(Snake& snake, Input input) override;
  virtual void Update(Snake& snake) override;
};