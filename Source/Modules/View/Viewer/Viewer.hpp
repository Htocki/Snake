#pragma once

#include <SFML/System/Vector2.hpp>

using WindowPosition = sf::Vector2f;
using SegmentSize = sf::Vector2f;

class Viewer {
public:
  Viewer(WindowPosition position, SegmentSize segmentSize);
  void Render(sf::RenderWindow& window, const ModelData& data);

private:
  Position m_position;
  SegmentSize m_segmentSize;
};