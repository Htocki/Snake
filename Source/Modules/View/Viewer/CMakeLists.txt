set(LIBRARY_NAME viewer)

add_library(${LIBRARY_NAME}
  Viewer.cpp
  Viewer.hpp
)

target_include_directories(${LIBRARY_NAME}
  PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)

target_link_libraries(${LIBRARY_NAME}
  PRIVATE
    sfml-graphics
)