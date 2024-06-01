#include <gtest/gtest.h>

#include "Field.hpp"

TEST(Field, Resize) {
  Size size { 5, 7 };
  Field field { size };
  // Проверка размера поля.
  EXPECT_EQ(field.GetSize(), size);
  // Проверка состояния сегментов поля.
  bool result { true };
  for (auto i { 0u }; i < size.x; ++i) {
    for (auto j { 0u }; j < size.y; ++j ) {
      if (field.GetElement(Position { i, j }) != SegmentState::Empty) {
        result = false;
      }
    }
  }
  EXPECT_EQ(result, true);
}

TEST(Field, SetElement) {
  Size size { 10, 7 };
  Field field { size };
  Position position { 8, 5 };
  field.SetElement(position, SegmentState::Barrier);
  // Проверка состояния ячейки.
  EXPECT_EQ(field.GetElement(position), SegmentState::Barrier);
}

#include <iostream>

TEST(Field, AddBorder) {
  Size size { 10, 7 };
  Field field { size };
  field.AddBorder();
  // Выборочная проверка сегментов границы.
  EXPECT_EQ(field.GetElement(Position { 2, 0 }), SegmentState::Barrier);
  EXPECT_EQ(field.GetElement(Position { 3, 6 }), SegmentState::Barrier);
  EXPECT_EQ(field.GetElement(Position { 0, 5 }), SegmentState::Barrier);
  EXPECT_EQ(field.GetElement(Position { 9, 4 }), SegmentState::Barrier);
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}