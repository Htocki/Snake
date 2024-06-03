#pragma once

#include "Field.hpp"

class Apple {
public:
  Apple(Field& field);
  void Respawn();

private:
  Field& m_field;
};