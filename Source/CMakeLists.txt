cmake_minimum_required(VERSION 3.28)

project("application"
  LANGUAGES CXX
  VERSION 1.0
)

include(FetchContent)

FetchContent_Declare(
  sfml
  GIT_REPOSITORY https://github.com/SFML/SFML.git
  GIT_TAG        2.6.1
)

FetchContent_MakeAvailable(sfml)

add_executable("executable"
  Main.cpp
)

target_link_libraries("executable"
  PRIVATE
    game
)

add_subdirectory(Apple)
add_subdirectory(Field)
add_subdirectory(Game)
add_subdirectory(Snake)
add_subdirectory(Textbox)
add_subdirectory(Window)
add_subdirectory(World)