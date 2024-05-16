add_library("world"
  World.cpp
  World.hpp
)

target_include_directories("world"
  PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)

target_link_libraries("world"
  PUBLIC
    sfml-graphics
    field
    snake
)