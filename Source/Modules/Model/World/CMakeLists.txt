set(LIBRARY_NAME world)

add_library(${LIBRARY_NAME}
  World.cpp
  World.hpp
)

target_include_directories(${LIBRARY_NAME}
  PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)

target_link_libraries(${LIBRARY_NAME}
  PUBLIC
    sfml-system
    apple
    data
    field
    input
    snake
)