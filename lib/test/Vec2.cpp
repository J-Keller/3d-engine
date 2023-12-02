//
// Created by Jonas on 7/1/23.
//

#include <gtest/gtest.h>
#include <list>
#include "../src/math/types/Vec2.h"

template<typename T>
class Vec2TestSuite : public testing::Test {
 public:
  using List = std::list<T>;
  static T shared_;
  T value_{};
};

using Vec2TypeList = ::testing::Types<int, float>;
TYPED_TEST_SUITE(Vec2TestSuite, Vec2TypeList);

// Demonstrate some basic assertions.
TYPED_TEST(Vec2TestSuite, Comparison) {

  Vec2<TypeParam> a(1, 2);
  Vec2<TypeParam> b(1, 2);
  EXPECT_TRUE(a == b);

  b = Vec2<TypeParam>(2, 1);
  EXPECT_TRUE(a != b);
}

TYPED_TEST(Vec2TestSuite, Addition) {
  Vec2<TypeParam> a(1, 2);
  Vec2<TypeParam> b(2, 1);

  Vec2<TypeParam> c(3, 3);
  EXPECT_EQ(a + b, c);

  Vec2<TypeParam> d(2, 2);
  EXPECT_NE(a + b, d);
}

TYPED_TEST(Vec2TestSuite, Multiplication) {
  // Dot
  Vec2<TypeParam> a(1, 2);
  Vec2<TypeParam> b(2, 1);
  EXPECT_EQ(a * b, 4);

  // Scalar
  Vec2<TypeParam> c(4, 8);
  TypeParam scalar = 4;
  EXPECT_EQ(a * scalar, c);
}