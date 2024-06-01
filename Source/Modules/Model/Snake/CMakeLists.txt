add_library("snake"
  Snake.cpp
  Snake.hpp
  SnakeState.cpp
  SnakeState.hpp
)

target_include_directories("snake"
  PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)

target_link_libraries("snake"
  PUBLIC
    sfml-graphics
    input
)