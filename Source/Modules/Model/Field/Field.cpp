#include "Field.hpp"

Field::Field(const Size& size) 
  : m_size { size }
{
  SetSize(size);
  AddBorder();
}

void Field::AddBorder() {
  // Добавление вертикальных границ.
  for (auto i { 0u }; i < m_size.x; ++i) {
    SetState(Position { i,            0 }, SegmentState::Border);
    SetState(Position { i, m_size.y - 1 }, SegmentState::Border);
  }
  // Добавление горизонтальных границ.
  for (auto i { 0u }; i < m_size.y; ++i) {
    SetState(Position { 0,            i }, SegmentState::Border);
    SetState(Position { m_size.x - 1, i }, SegmentState::Border);
  }
}

const Size& Field::GetSize() const {
  return m_size;
}

SegmentState Field::GetState(const Position& position) const {
  return m_matrix[position.x][position.y];
}

void Field::SetSize(const Size& size) {
  // Изменение размера матрицы.
  m_matrix.resize(size.x);
  for (auto& column : m_matrix) {
    column.resize(size.y);
  }
  // Установка состояния элементов матрицы, как пустых.
  for (auto& column : m_matrix) {
    for (auto& element : column) {
      element = SegmentState::Empty;
    }
  }
}

void Field::SetState(const Position& position, SegmentState state) {
  m_matrix[position.x][position.y] = state;
}
