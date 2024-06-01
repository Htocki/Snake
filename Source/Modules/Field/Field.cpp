#include "Field.hpp"

Field::Field(const Size& size) 
  : m_size { size }
{
  Resize(size);
}

void Field::AddBorder() {
  // Добавление вертикальных границ.
  for (auto i { 0u }; i < m_size.x; ++i) {
    SetElement(Position { i,            0 }, SegmentState::Barrier);
    SetElement(Position { i, m_size.y - 1 }, SegmentState::Barrier);
  }
  // Добавление горизонтальных границ.
  for (auto i { 0u }; i < m_size.y; ++i) {
    SetElement(Position { 0,            i }, SegmentState::Barrier);
    SetElement(Position { m_size.x - 1, i }, SegmentState::Barrier);
  }
}

SegmentState Field::GetElement(const Position& position) const {
  return m_matrix[position.x][position.y];
}

const Size& Field::GetSize() const {
  return m_size;
}

void Field::Resize(const Size& size) {
  // Изменение размера матрицы.
  m_matrix.resize(size.x);
  for (auto& column : m_matrix) {
    column.resize(size.y);
  }
  // Установка состояния элементов матрицы.
  for (auto& column : m_matrix) {
    for (auto& element : column) {
      element = SegmentState::Empty;
    }
  }
}

void Field::SetElement(const Position& position, SegmentState state) {
  m_matrix[position.x][position.y] = state;
}
