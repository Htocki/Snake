cmake_minimum_required(VERSION 3.28)

project("application"
  LANGUAGES CXX
  VERSION 1.0
)

if (CMAKE_COMPILER_IS_GNUCXX)
  add_definitions (-Wall -pedantic)
endif ()

if (CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME)
  include (CTest)
endif ()

enable_testing()

include(FetchContent)

FetchContent_Declare(
  sfml
  GIT_REPOSITORY https://github.com/SFML/SFML.git
  GIT_TAG        2.6.1
)
FetchContent_MakeAvailable(sfml)

FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest
  GIT_TAG        v1.14.0
)
FetchContent_MakeAvailable(googletest)

add_executable("executable"
  Main.cpp
)

target_link_libraries("executable"
  PRIVATE
    game
)

add_subdirectory(Modules/Game)
add_subdirectory(Modules/Input)
add_subdirectory(Modules/Model/Apple)
add_subdirectory(Modules/Model/Field)
add_subdirectory(Modules/Model/Snake)
add_subdirectory(Modules/Model/World)
add_subdirectory(Modules/Textbox)
add_subdirectory(Modules/Window)

add_subdirectory(Tests/Field)
add_subdirectory(Tests/Snake)