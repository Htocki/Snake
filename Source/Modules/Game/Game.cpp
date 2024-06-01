#include "Game.hpp"

#include <string>

#include <SFML/System/Vector2.hpp>
#include <SFML/Window/Keyboard.hpp>

Game::Game()
  : m_window { "", sf::Vector2u { 800, 600 }}
  , m_world { sf::Vector2u { 800, 600 }}
  , m_snake { sf::Vector2u { 5, 5 }}
  , m_textbox { 5, 14, 350.f, sf::Vector2f { 30.f, 30.f }}
{
  m_textbox.Add("Hello");
  m_textbox.Add("brave");
}

Game::~Game() {}

void Game::HandleInput() {
  Input input { Input::None };

  if      (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))  { input = Input::KbDown; }
  else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))  { input = Input::KbLeft; }
  else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) { input = Input::KbRight; }
  else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))    { input = Input::KbUp; }
  else                                                      { input = Input::None; }

  m_snake.HandleInput(input);
}

void Game::Update() {
  float timeStep { 1.0f / 15 };

  if (m_elapsed.asSeconds() >= timeStep) {
    m_snake.Update();
    m_world.Update(m_snake);
    m_elapsed -= sf::seconds(timeStep);

    if (m_snake.IsCollided()) {
      m_snake.Reset();
    }
  }

  m_window.Update();
}

void Game::Render() {
  m_window.Clear();
  m_world.Render(m_window.GetRenderWindow());
  m_snake.Render(m_window.GetRenderWindow());
  m_textbox.Render(m_window.GetRenderWindow());
  m_window.Display();
}

void Game::RestartClock() {
  m_elapsed += m_clock.restart();
}

sf::Time Game::GetElapsed() const {
  return m_elapsed;
}

bool Game::IsRun() const {
  return !m_window.IsDone();
}