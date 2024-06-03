#pragma once

#include <string>
#include <vector>

#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/System/Vector2.hpp>

using Messages = std::vector<std::string>;

class Textbox {
public:
  Textbox();
  Textbox(int visible, int charSize, float width, sf::Vector2f screenPos);
  ~Textbox();

  void Add(std::string message);
  void Render(sf::RenderWindow& window);

private:
  Messages m_messages;
  int m_numVisible;

  sf::RectangleShape m_backdrop;
  sf::Font m_font;
  sf::Text m_content;
};