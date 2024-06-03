set(LIBRARY_NAME snake)

add_library(${LIBRARY_NAME}
  Snake.cpp
  Snake.hpp
  SnakeState.cpp
  SnakeState.hpp
)

target_include_directories(${LIBRARY_NAME}
  PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)

target_link_libraries(${LIBRARY_NAME}
  PUBLIC
    sfml-graphics
    field
    input
)