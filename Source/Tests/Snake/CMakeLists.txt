set(TEST_NAME "snake-test")
set(EXECUTABLE_NAME "snake-test-executable")

add_executable(${EXECUTABLE_NAME}
  Main.cpp
)

add_test(NAME ${TEST_NAME} COMMAND ${EXECUTABLE_NAME})

target_link_libraries(${EXECUTABLE_NAME}
  GTest::gtest_main
  snake
)