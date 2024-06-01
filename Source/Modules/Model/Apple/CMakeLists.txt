add_library("apple"
  Apple.cpp
  Apple.hpp
)

target_include_directories("apple"
  PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)

target_link_libraries("apple"
  PUBLIC
    sfml-system
    field
)