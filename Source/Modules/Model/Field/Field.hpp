#pragma once

#include <vector>

#include <SFML/System/Vector2.hpp>

enum class SegmentState {
  Apple,
  Border,
  Empty,
  Snake
};

using Matrix = std::vector<std::vector<SegmentState>>;
using Position = sf::Vector2u;
using Size = sf::Vector2u;

class Field {
  void AddBorder();

public:
  Field(const Size& size);
  const Size&  GetSize() const;
  SegmentState GetState(const Position& position) const;
  void         SetSize(const Size& size);
  void         SetState(const Position& position, SegmentState state);

private:
  Matrix m_matrix;
  Size   m_size;
};