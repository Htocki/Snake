set(TEST_NAME "field-test")
set(EXECUTABLE_NAME "field-test-executable")

add_executable(${EXECUTABLE_NAME}
  Main.cpp
)

add_test(NAME ${TEST_NAME} COMMAND ${EXECUTABLE_NAME})

target_link_libraries(${EXECUTABLE_NAME}
  GTest::gtest_main
  field
)