set(LIBRARY_NAME textbox)

add_library(${LIBRARY_NAME}
  Textbox.cpp
  Textbox.hpp
)

target_include_directories(${LIBRARY_NAME}
  PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)

target_link_libraries(${LIBRARY_NAME}
  PRIVATE
    sfml-graphics
)