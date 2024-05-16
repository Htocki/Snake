add_library("field"
  Field.cpp
  Field.hpp
)

target_include_directories("field"
  PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)

target_link_libraries("field"
  PUBLIC
    sfml-graphics
    sfml-system
)