add_library("window"
  Window.cpp
  Window.hpp
)

target_include_directories("snake"
  PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)

target_link_libraries("window"
  PRIVATE
    sfml-graphics
    sfml-window
)