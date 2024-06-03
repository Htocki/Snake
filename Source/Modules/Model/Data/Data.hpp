#pragma once

#include <vector>

#include <SFML/System/Vector2.hpp>

using Value = unsigned int;
using Position = sf::Vector2u;

struct SegmentData {
  Position position { 0u, 0u };
  Value    value    { 0u };
};

using FieldData = std::vector<std::vector<SegmentData>>;

struct Data {
  FieldData fieldData;
};