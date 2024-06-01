#include "Field.hpp"

Field::Field(const Size& size) 
  : m_size { size }
{
  Resize(size);
}

SegmentState Field::GetElement(const Position& position) const {
  return m_matrix[position.x][position.y];
}

Size Field::GetSize() const {
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
