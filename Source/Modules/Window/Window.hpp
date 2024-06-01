#pragma once

#include <string>

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Vector2.hpp>

class Window {
public:
  Window();
  Window(const std::string& title, const sf::Vector2u& size);
  ~Window();

  void Clear();
  void Draw(sf::Drawable& drawable);
  void Display();
  void Update();
  void ToggleFullScreen();

  bool IsDone() const;
  bool IsFullScreen() const;

  sf::Vector2u GetSize() const;
  sf::RenderWindow& GetRenderWindow();

private:
  void Setup(const std::string& title, const sf::Vector2u& size);
  void Destroy();
  void Create();

  sf::RenderWindow m_window;
      sf::Vector2u m_size;
       std::string m_title;
              bool m_isDone;
              bool m_isFullScreen;
};