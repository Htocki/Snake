#include "Window.hpp"

#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>

Window::Window() {
  Setup("Window", sf::Vector2u(640, 480));
}

Window::Window(const std::string& title, const sf::Vector2u& size) {
  Setup(title, size);
}

Window::~Window() {
  Destroy();
}

void Window::Setup(const std::string& title, const sf::Vector2u& size) {
  m_title = title;
  m_size = size;
  m_isFullScreen = false;
  m_isDone = false;
  Create();
}

void Window::Create() {
  sf::Uint32 style = (
    m_isFullScreen ? sf::Style::Fullscreen : sf::Style::Default
  );
  m_window.create({ m_size.x, m_size.y, 32 }, m_title, style);
}

void Window::Destroy() {
  m_window.close();
}

void Window::Update() {
  sf::Event event;
  while (m_window.pollEvent(event)) {
    switch(event.type) {
      case sf::Event::Closed:
        m_isDone = true;
        break;
      case sf::Event::KeyPressed:
        if (event.key.code == sf::Keyboard::F5) {
          ToggleFullScreen();
        }
        break;
      default:
        break;
    }
  }
}

void Window::ToggleFullScreen() {
  m_isFullScreen = not m_isFullScreen;
  Destroy();
  Create();
}

void Window::Clear() {
  m_window.clear(sf::Color::Black);
}

void Window::Display() {
  m_window.display();
}

bool Window::IsDone() const {
  return m_isDone;
}

bool Window::IsFullScreen() const {
  return m_isFullScreen;
}

sf::Vector2u Window::GetSize() const {
  return m_size;
}

void Window::Draw(sf::Drawable& drawable) {
  m_window.draw(drawable);
}

sf::RenderWindow& Window::GetRenderWindow() {
  return m_window;
}