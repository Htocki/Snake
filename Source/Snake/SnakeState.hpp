#pragma once

#include "Input.hpp"
#include "Snake.hpp"

class MovingDownState;
class MovingLeftState;
class MovingRightState;
class MovingUpState;
class StandingState;

class SnakeState {
public:
  static MovingDownState  movingDown;
  static MovingLeftState  movingLeft;
  static MovingRightState movingRight;
  static MovingUpState    movingUp;
  static StandingState    standing; 

  virtual ~SnakeState() {} 
  virtual void HandleInput(Snake& snake, Input input) = 0;
  virtual void Update(Snake& snake) = 0;
};

class MovingDownState : public SnakeState {
public:
  MovingDownState();
  virtual void HandleInput(Snake& snake, Input input) override;
  virtual void Update(Snake& snake) override;
};

class MovingLeftState : public SnakeState {
public:
  MovingLeftState();
  virtual void HandleInput(Snake& snake, Input input) override;
  virtual void Update(Snake& snake) override;
};

class MovingRightState : public SnakeState {
public:
  MovingRightState();
  virtual void HandleInput(Snake& snake, Input input) override;
  virtual void Update(Snake& snake) override;
};

class MovingUpState : public SnakeState {
public:
  MovingUpState();
  virtual void HandleInput(Snake& snake, Input input) override;
  virtual void Update(Snake& snake) override;
};

class StandingState : public SnakeState {
public:
  StandingState();
  virtual void HandleInput(Snake& snake, Input input) override;
  virtual void Update(Snake& snake) override;
};