add_library("textbox"
  Textbox.cpp
  Textbox.hpp
)

target_include_directories("snake"
  PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)

target_link_libraries("textbox"
  PRIVATE
    sfml-graphics
)