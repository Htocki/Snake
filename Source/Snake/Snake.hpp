#pragma once

#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Vector2.hpp>

#include "Input.hpp"

class SnakeState;

class Snake {
public:
  Snake();
  ~Snake();

  bool IsCollided() const;

  void HandleInput(Input input);
  void Update();
  void Render(sf::RenderWindow& window);
  void Reset();
  
  SnakeState* m_state;

private:
  void CheckCollision();
  
  bool m_isCollided;
};

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