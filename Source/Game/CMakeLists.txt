add_library("game"
  Game.cpp
  Game.hpp
)

target_include_directories("game"
  PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)

target_link_libraries("game"
  PUBLIC
    sfml-system
    sfml-window
    snake
    textbox
    window
    world
)