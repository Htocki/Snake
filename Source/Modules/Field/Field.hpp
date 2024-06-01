#pragma once

#include <vector>

#include <SFML/System/Vector2.hpp>

enum class SegmentState {
  Barrier,
  Empty,
  Snake
};

using Matrix = std::vector<std::vector<SegmentState>>;
using Position = sf::Vector2u;
using Size = sf::Vector2u;

class Field {
public:
  Field(const Size& size);
  SegmentState GetElement(const Position& position) const;
  Size         GetSize() const;
  void         Resize(const Size& size);
  void         SetElement(const Position& position, SegmentState state);

private:
  Matrix m_matrix;
  Size   m_size;
};