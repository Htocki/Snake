set(LIBRARY_NAME input)

add_library(${LIBRARY_NAME}
  Input.hpp
  Input.cpp
)

target_include_directories(${LIBRARY_NAME}
  PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)