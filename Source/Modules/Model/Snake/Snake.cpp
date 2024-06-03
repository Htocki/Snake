#include "Snake.hpp"

#include <cstdlib>
#include <ctime>

#include "SnakeState.hpp"

bool Snake::IsBorder(const Position& position) const {
  return m_field.GetState(position) == SegmentState::Border;
}

Snake::Snake(Field& field)
  : m_field { field }
  , m_state { new StandingState() }
{}

Snake::~Snake() { delete m_state; }

void Snake::HandleInput(Input input) {
  SnakeState* state = m_state->HandleInput(*this, input);
  delete m_state;
  m_state = state;
}

void Snake::MoveDown() {
  // Обработка столкновения с границей.
  Position next { m_segments[0].x, m_segments[0].y + 1 };
  if (IsBorder(next)) {
    Respawn();
    return;
  }
  m_segments[0].y += 1;
  // Обработка столкновения с яблоком.
  // Обработка столкновения с хвостом змейки.
}

void Snake::MoveLeft() {
  // Обработка столкновения с границей.
  Position next { m_segments[0].x - 1, m_segments[0].y };
  if (IsBorder(next)) {
    Respawn();
    return;
  }
  m_segments[0].x -= 1;
  // Обработка столкновения с яблоком.
  // Обработка столкновения с хвостом змейки.
}

void Snake::MoveRight() {
  // Обработка столкновения с границей.
  Position next { m_segments[0].x + 1, m_segments[0].y };
  if (IsBorder(next)) {
    Respawn();
    return;
  }
  m_segments[0].x += 1;
  // Обработка столкновения с яблоком.
  // Обработка столкновения с хвостом змейки.
}

void Snake::MoveUp() {
  // Обработка столкновения с границей.
  Position next { m_segments[0].x, m_segments[0].y - 1 };
  if (IsBorder(next)) {
    Respawn();
    return;
  }
  m_segments[0].y -= 1;
  // Обработка столкновения с яблоком.
  // Обработка столкновения с хвостом змейки.
}

void Snake::Respawn() {
  // Генерация новой позиции для головы змейки.
  Position position;
  std::srand(std::time(nullptr));
  do {
    position.x = std::rand() % m_field.GetSize().x;
    position.y = std::rand() % m_field.GetSize().y;
  } while (m_field.GetState(position) != SegmentState::Empty);
  // Переопределение контейнера с сегментами змейки.
  m_segments.clear();
  m_segments.push_back(position);
  // Переопределение состояния змейки.
  delete m_state;
  m_state = new StandingState();
}

void Snake::SetField(Field& field) { m_field = field; }

void Snake::Update() {
  m_state->Update(*this);
  /* Где-то тут нужно добавить удаление старой змейки
     с поля и добавление на него новой.
  */
}