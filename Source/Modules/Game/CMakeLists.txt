set(LIBRARY_NAME game)

add_library(${LIBRARY_NAME}
  Game.cpp
  Game.hpp
)

target_include_directories(${LIBRARY_NAME}
  PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)

target_link_libraries(${LIBRARY_NAME}
  PUBLIC
    sfml-system
    sfml-window
    input
    snake
    textbox
    window
    world
)