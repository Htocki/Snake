#pragma once

#include <vector>

#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Vector2.hpp>

struct SnakeSegment {
  SnakeSegment(int x, int y)
    : position { x, y }
  {}

  sf::Vector2i position;
};

using SnakeSegments = std::vector<SnakeSegment>;

enum class Direction { None, Up, Down, Left, Right };

class Snake {
public:
  Snake(int blockSize);
  ~Snake();

  void SetDirection(Direction direction);

  Direction GetDirection() const;
  int GetSpeed() const;
  sf::Vector2i GetPosition() const;
  int GetLives() const;
  int GetScore() const;
  Direction GetPhysicalDirection();

  bool HasLost() const;
  
  void IncreaseScore();
  void Lose();  // Handle losing here.
  void ToggleLost();
  void Extend();  // Grow the snake.
  void Move();  // Movement method.
  void Cut(int segments);  // Method for cutting snake.
  void Reset();
  
  void Update();
  void Render(sf::RenderWindow& window);

private:
  void CheckCollision();  // Checking for collisions.

       SnakeSegments m_snakeBody;  // Segment vector.
                 int m_size;       // Size of the graphics.
           Direction m_direction;  // Current direction.
                 int m_speed;      // Speed of the snake.
                 int m_lives;      // Lives.
                 int m_score;      // Score.
                bool m_lost;       // Losing state.
  sf::RectangleShape m_bodyRect;   // Shape used in rendering.
};

