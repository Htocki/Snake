#include "Game.hpp"

#include <string>

#include <SFML/System/Vector2.hpp>
#include <SFML/Window/Keyboard.hpp>

Game::Game()
  : m_window { "", sf::Vector2u { 800, 600 }}
  , m_snake { m_world.GetBlockSize() }
  , m_world { sf::Vector2u { 800, 600 }}
  , m_textbox { 5, 14, 350.f, sf::Vector2f { 30.f, 30.f }}
{
  m_textbox.Add("Hello");
  m_textbox.Add("brave");
  m_textbox.Add("new");
  m_textbox.Add("world");
}

Game::~Game() {}

void Game::HandleInput() {
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && m_snake.GetPhysicalDirection() != Direction::Down) {
    m_snake.SetDirection(Direction::Up);
  } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && m_snake.GetPhysicalDirection() != Direction::Up) {
    m_snake.SetDirection(Direction::Down);
  } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && m_snake.GetPhysicalDirection() != Direction::Right) {
    m_snake.SetDirection(Direction::Left);
  } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && m_snake.GetPhysicalDirection() != Direction::Left) {
    m_snake.SetDirection(Direction::Right);
  }
}

void Game::Update() {
  float timeStep { 1.0f / m_snake.GetSpeed() };

  if (m_elapsed.asSeconds() >= timeStep) {
    m_snake.Update();
    m_world.Update(m_snake);
    m_elapsed -= sf::seconds(timeStep);

    if (m_snake.HasLost()) {
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