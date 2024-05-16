#include "Field.hpp"

Field::Field(sf::Vector2u windowSize, int blockSize) {
  // Определение размера в сегментах.
  sf::Vector2u size {
    windowSize.x / blockSize,
    windowSize.y / blockSize
  };
  
  // Выделение памяти под сегменты.
  m_segments.resize(size.x);
  for (auto& column : m_segments) {
    column.resize(size.y);
  }
  
  // Определение базовых характеристик сегментов и их расположения.
  for (int i { 0 }; i < m_segments.size(); ++i) {
    for (int j { 0 }; j < m_segments[0].size(); ++j) {
      m_segments[i][j].setPosition(blockSize * i, blockSize * j);
      m_segments[i][j].setSize(sf::Vector2f { blockSize - 1.f, blockSize - 1.f });
      m_segments[i][j].setFillColor(sf::Color::Transparent);
    }
  }
  
  // Изменение цвета сегментов отвечающих за горизонтальные границы.
  for (int i { 0 }; i < m_segments.size(); ++i) {
    m_segments[i][0].setFillColor(sf::Color::Green);
    m_segments[i][size.y - 1].setFillColor(sf::Color::Green);
  }
  
  // Изменение цвета сегментов отвечающих за вертикальные границы.
  for (int j { 0 }; j < m_segments[0].size(); ++j) {
    m_segments[0][j].setFillColor(sf::Color::Green);
    m_segments[size.x - 1][j].setFillColor(sf::Color::Green);
  }
}

Field::~Field() {}

bool Field::IsBorder(sf::Vector2i gridPosition) const {
  if (m_segments[gridPosition.x][gridPosition.y].getFillColor() == sf::Color::Green) {
    return true;
  } else {
    return false;
  }
}

void Field::Render(sf::RenderWindow& window) const {
  for (auto column : m_segments) {
    for (auto segment : column) {
      window.draw(segment);
    }
  }
}