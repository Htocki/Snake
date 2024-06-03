#include "World.hpp"

void World::UpdateData() {}

World::World(const Size& size) 
  : m_field { size }
  , m_apple { m_field }
  , m_snake { m_field }
  , m_data {}
{}

const Data& World::GetData() const { return m_data; }

void World::HandleInput(Input input) {
  m_snake.HandleInput(input);
}

void World::Update() {
  //if (змейка.съелаЯблоко())     { m_apple.Respawn(); }
  //if (змейка.удариласьОСтену()) { m_apple.Respawn(); }
  m_snake.Update();
  UpdateData();
}