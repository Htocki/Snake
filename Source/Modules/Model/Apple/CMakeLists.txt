set(LIBRARY_NAME apple)

add_library(${LIBRARY_NAME}
  Apple.cpp
  Apple.hpp
)

target_include_directories(${LIBRARY_NAME}
  PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)

target_link_libraries(${LIBRARY_NAME}
  PUBLIC
    sfml-system
    field
)