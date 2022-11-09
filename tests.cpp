#include <gtest/gtest.h>

#include <cmath>

#include "model/Calc/calculator.h"
#include "model/Calc/data.h"

TEST(calc, sum) {
  Calc::Calculator calc;
  calc.insertAliasString("5p5");
  double a = calc.result().first.at(0);
  double b = 5 + 5;
  EXPECT_DOUBLE_EQ(a, b);
}

TEST(calc, sub) {
  Calc::Calculator calc;
  calc.insertAliasString("6m5");
  double a = calc.result().first.at(0);
  double b = 6 - 5;
  EXPECT_DOUBLE_EQ(a, b);
}

TEST(calc, mul) {
  Calc::Calculator calc;
  calc.insertAliasString("100*100.1");
  double a = calc.result().first.at(0);
  double b = 100 * 100.1;
  EXPECT_DOUBLE_EQ(a, b);
}

TEST(calc, div) {
  Calc::Calculator calc;
  calc.insertAliasString("100/10");
  double a = calc.result().first.at(0);
  double b = 100 / 10;
  EXPECT_DOUBLE_EQ(a, b);
}

TEST(calc, mod) {
  Calc::Calculator calc;
  calc.insertAliasString("66.6%3");
  double a = calc.result().first.at(0);
  double b = fmod(66.6, 3);
  EXPECT_DOUBLE_EQ(a, b);
}

TEST(calc, brackets) {
  Calc::Calculator calc;
  calc.insertAliasString("(63p3)*0.5");
  double a = calc.result().first.at(0);
  double b = (63 + 3) * 0.5;
  EXPECT_DOUBLE_EQ(a, b);
}

TEST(calc, unary_minus) {
  Calc::Calculator calc;
  calc.insertAliasString("m6pm0.5");
  double a = calc.result().first.at(0);
  double b = -6 + -0.5;
  EXPECT_DOUBLE_EQ(a, b);
}

TEST(calc, unary_plus) {
  Calc::Calculator calc;
  calc.insertAliasString("p6pp0.5");
  double a = calc.result().first.at(0);
  double b = +6 + +0.5;
  EXPECT_DOUBLE_EQ(a, b);
}

TEST(calc, unary_minus_in_brackets) {
  Calc::Calculator calc;
  calc.insertAliasString("m6p(m0.5)p5");
  double a = calc.result().first.at(0);
  double b = -6 + (-0.5) + 5;
  EXPECT_DOUBLE_EQ(a, b);
}

TEST(calc, extent) {
  Calc::Calculator calc;
  calc.insertAliasString("2^3");
  double a = calc.result().first.at(0);
  double b = pow(2, 3);
  EXPECT_DOUBLE_EQ(a, b);
}

TEST(calc, extent_and_brackets) {
  Calc::Calculator calc;
  calc.insertAliasString("2^(3^(3^1))");
  double a = calc.result().first.at(0);
  double b = pow(2, 27);
  EXPECT_DOUBLE_EQ(a, b);
}

TEST(calc, long_ex) {
  Calc::Calculator calc;
  calc.insertAliasString("1336m133.4*63m166/6.3");
  double a = calc.result().first.at(0);
  double b = 1336 - 133.4 * 63 - 166 / 6.3;
  EXPECT_DOUBLE_EQ(a, b);
}

TEST(calc, exponenta) {
  Calc::Calculator calc;
  calc.insertAliasString("1.E3m10.1");
  double a = calc.result().first.at(0);
  double b = 1.e3 - 10.1;
  EXPECT_DOUBLE_EQ(a, b);
}

TEST(calc, sin_cos_tan) {
  Calc::Calculator calc;
  calc.insertAliasString("s0.6)pc3)mt1.13)");
  double a = calc.result().first.at(0);
  double b = sin(0.6) + cos(3) - tan(1.13);
  EXPECT_DOUBLE_EQ(a, b);
}

TEST(calc, acos_asin_atan) {
  Calc::Calculator calc;
  calc.insertAliasString("C0.06)*T0.3)mS0.99)");
  double a = calc.result().first.at(0);
  double b = acos(0.06) * atan(0.3) - asin(.99);
  EXPECT_DOUBLE_EQ(a, b);
}

TEST(calc, sqrt) {
  Calc::Calculator calc;
  calc.insertAliasString("Q0.06)");
  double a = calc.result().first.at(0);
  double b = sqrt(0.06);
  EXPECT_DOUBLE_EQ(a, b);
}

TEST(calc, log_log10) {
  Calc::Calculator calc;
  calc.insertAliasString("l2.17)pL6.66)");
  double a = calc.result().first.at(0);
  double b = log(2.17) + log10(6.66);
  EXPECT_DOUBLE_EQ(a, b);
}

TEST(calc, display_text) {
  Calc::Calculator calc;
  calc.insertAliasString("l2.17)pL6.66)p");
  std::string check1("ln(2.17)+log(6.66)+");
  std::string result1(calc.getDisplayString());
  EXPECT_TRUE(check1 == result1);
  if (calc.remove()) {
    std::string check2("ln(2.17)+log(6.66)");
    std::string result2(calc.getDisplayString());
    EXPECT_TRUE(check2 == result2);
  }
}

TEST(calc, x_var) {
  Calc::Calculator calc;
  calc.insertAliasString("Tx)");
  EXPECT_TRUE(calc.hasX() == true);
  double x = 0.5;
  auto pair_x = std::make_pair(x, x);
  calc.setX(pair_x);
  auto getX = calc.getX();
  EXPECT_DOUBLE_EQ(getX.first, x);
  EXPECT_DOUBLE_EQ(getX.second, x);
  double a = calc.result().first.at(0);
  double b = atan(x);
  EXPECT_DOUBLE_EQ(round(a), round(b));
}

TEST(calc, x_var2) {
  Calc::Calculator calc;
  calc.insertAliasString("Tx)");
  EXPECT_TRUE(calc.hasX() == true);
  double x1 = 0.5, x2 = 1.5;
  auto pair_x = std::make_pair(x2, x1);
  calc.setX(pair_x);
  auto getX = calc.getX();
  EXPECT_DOUBLE_EQ(getX.first, x1);
  EXPECT_DOUBLE_EQ(getX.second, x2);
  double a = calc.result().first.at(0);
  double b = atan(x1);
  EXPECT_DOUBLE_EQ(round(a), round(b));
}

TEST(calc, pi_var) {
  Calc::Calculator calc;
  calc.insertAliasString("li)");
  double a = calc.result().first.at(0);
  double b = log(M_PI);
  EXPECT_DOUBLE_EQ(round(a), round(b));
}

TEST(calc, euler_var) {
  Calc::Calculator calc;
  calc.insertAliasString("Le)");
  double a = calc.result().first.at(0);
  double b = log10(M_E);
  EXPECT_DOUBLE_EQ(round(a), round(b));
}

TEST(calc, can_calc) {
  Calc::Calculator calc;
  calc.insertAliasString("Le)");
  EXPECT_TRUE(calc.canCalculate() == true);
}

TEST(calc, remove_check) {
  Calc::Calculator calc;
  EXPECT_TRUE(calc.remove() == false);

  calc.append(Calc_Alias::ADD);
  calc.append(Calc_Alias::SIN);
  EXPECT_TRUE(calc.remove() == true);
  EXPECT_TRUE(calc.remove() == true);
  EXPECT_TRUE(calc.remove() == false);

  calc.reset();
  EXPECT_TRUE(calc.insertAliasString("s1.3)") == true);
  EXPECT_TRUE(calc.remove() == true);
  EXPECT_TRUE(calc.remove() == true);
  std::string display(calc.getDisplayString());
  std::string check("sin(1.");
  EXPECT_TRUE(display == check);

  calc.reset();
  calc.insertAliasString("s1.");
  calc.append(Calc_Alias::E);
  EXPECT_TRUE(calc.remove() == true);
  EXPECT_TRUE(calc.remove() == true);
  calc.append(Calc_Alias::E);
  calc.append(Calc_Alias::ZERO);
  calc.append(Calc_Alias::BRC);
  std::string display2(calc.getDisplayString());
  std::string check2("sin(1E0)");
  EXPECT_TRUE(display2 == check2);

  calc.reset();
  calc.insertAliasString("p5pm5");
  EXPECT_TRUE(calc.remove() == true);
  std::string display3(calc.getDisplayString());
  std::string check3("+5+-");
  EXPECT_TRUE(display3 == check3);
}

int main(int argc, char *argv[]) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
