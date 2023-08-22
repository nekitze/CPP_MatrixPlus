#include "gtest/gtest.h"
#include "s21_matrix_oop.h"

TEST(EqualTest, Equal) {
  S21Matrix m1;
  S21Matrix m2;
  EXPECT_EQ(m1.EqMatrix(m2), true);
}

TEST(EqualTest, NotEqual) {
  S21Matrix m1;
  S21Matrix m2;
  m2.SetRows(2);
  EXPECT_EQ(m1.EqMatrix(m2), false);
}

TEST(EqualTest, EqualValues) {
  S21Matrix m1(2, 2);
  S21Matrix m2(2, 2);
  m1(0, 0) = 0;
  m1(0, 1) = 1;
  m1(1, 0) = 2;
  m1(1, 1) = 3;

  m2(0, 0) = 0;
  m2(0, 1) = 1;
  m2(1, 0) = 2;
  m2(1, 1) = 3;
  EXPECT_EQ(m1.EqMatrix(m2), true);
}

TEST(EqualTest, Operator) {
  S21Matrix m1(2, 2);
  S21Matrix m2(2, 2);
  m1(0, 0) = 0;
  m1(0, 1) = 1;
  m1(1, 0) = 2;
  m1(1, 1) = 3;

  m2(0, 0) = 0;
  m2(0, 1) = 1;
  m2(1, 0) = 2;
  m2(1, 1) = 3;
  EXPECT_EQ(m1 == m2, true);
}

TEST(SumTest, Sum) {
  S21Matrix m1(2, 2);
  S21Matrix m2(2, 2);

  m1(0, 0) = 0;
  m1(0, 1) = 1;
  m1(1, 0) = 2;
  m1(1, 1) = 3;

  m2(0, 0) = 0;
  m2(0, 1) = 1;
  m2(1, 0) = 2;
  m2(1, 1) = 3;

  m1.SumMatrix(m2);

  EXPECT_EQ(m1(0, 1), 2);
}

TEST(SumTest, Operator) {
  S21Matrix m1(2, 2);
  S21Matrix m2(2, 2);

  m1(0, 0) = 0;
  m1(0, 1) = 1;
  m1(1, 0) = 2;
  m1(1, 1) = 3;

  m2(0, 0) = 0;
  m2(0, 1) = 1;
  m2(1, 0) = 2;
  m2(1, 1) = 3;

  double res = (m1 + m2)(0, 1);

  EXPECT_EQ(res, 2.0);
}

TEST(SumTest, Assignment) {
  S21Matrix m1(2, 2);
  S21Matrix m2(2, 2);

  m1(0, 0) = 0;
  m1(0, 1) = 1;
  m1(1, 0) = 2;
  m1(1, 1) = 3;

  m2(0, 0) = 0;
  m2(0, 1) = 1;
  m2(1, 0) = 2;
  m2(1, 1) = 3;

  m1 += m2;

  EXPECT_EQ(m1(0, 1), 2.0);
}

TEST(SubTest, Sub) {
  S21Matrix m1(2, 2);
  S21Matrix m2(2, 2);

  m1(0, 0) = 0;
  m1(0, 1) = 1;
  m1(1, 0) = 2;
  m1(1, 1) = 3;

  m2(0, 0) = 0;
  m2(0, 1) = 1;
  m2(1, 0) = 2;
  m2(1, 1) = 3;

  m1.SubMatrix(m2);

  EXPECT_EQ(m1(0, 1), 0);
}

TEST(SubTest, Operator) {
  S21Matrix m1(2, 2);
  S21Matrix m2(2, 2);

  m1(0, 0) = 0;
  m1(0, 1) = 1;
  m1(1, 0) = 2;
  m1(1, 1) = 3;

  m2(0, 0) = 0;
  m2(0, 1) = 1;
  m2(1, 0) = 2;
  m2(1, 1) = 3;

  double res = (m1 - m2)(0, 1);

  EXPECT_EQ(res, 0);
}

TEST(SubTest, Assignment) {
  S21Matrix m1(2, 2);
  S21Matrix m2(2, 2);

  m1(0, 0) = 0;
  m1(0, 1) = 1;
  m1(1, 0) = 2;
  m1(1, 1) = 3;

  m2(0, 0) = 0;
  m2(0, 1) = 1;
  m2(1, 0) = 2;
  m2(1, 1) = 3;

  m1 -= m2;

  EXPECT_EQ(m1(0, 1), 0);
}

TEST(MulNumberTest, MulNumber) {
  S21Matrix m(2, 2);

  m(0, 0) = 0;
  m(0, 1) = 1;
  m(1, 0) = 2;
  m(1, 1) = 3;

  m.MulNumber(2);

  EXPECT_EQ(m(1, 0), 4);
}

TEST(MulNumberTest, OperatorRight) {
  S21Matrix m(2, 2);

  m(0, 0) = 0;
  m(0, 1) = 1;
  m(1, 0) = 2;
  m(1, 1) = 3;

  double res = (m * 2)(1, 0);

  EXPECT_EQ(res, 4);
}

TEST(MulNumberTest, OperatorLeft) {
  S21Matrix m(2, 2);

  m(0, 0) = 0;
  m(0, 1) = 1;
  m(1, 0) = 2;
  m(1, 1) = 3;

  double res = (2 * m)(1, 0);

  EXPECT_EQ(res, 4);
}

TEST(MulNumberTest, Assignment) {
  S21Matrix m(2, 2);

  m(0, 0) = 0;
  m(0, 1) = 1;
  m(1, 0) = 2;
  m(1, 1) = 3;

  m *= 2;

  EXPECT_EQ(m(1, 0), 4);
}

TEST(MulMatrixTest, MulMatrix) {
  S21Matrix m1(2, 2);
  S21Matrix m2(2, 2);

  m1(0, 0) = 0;
  m1(0, 1) = 1;
  m1(1, 0) = 2;
  m1(1, 1) = 3;

  m2(0, 0) = 0;
  m2(0, 1) = 1;
  m2(1, 0) = 2;
  m2(1, 1) = 3;

  m1.MulMatrix(m2);

  EXPECT_EQ(m1(1, 1), 11);
}

TEST(MulMatrixTest, MulMatrixRotate) {
  S21Matrix m1(2, 2);
  S21Matrix m2(2, 4);

  m1(0, 0) = 0;
  m1(0, 1) = 1;
  m1(1, 0) = 2;
  m1(1, 1) = 3;

  m2(0, 0) = 0;
  m2(0, 1) = 1;
  m2(0, 2) = 0;
  m2(0, 3) = 5;
  m2(1, 0) = 2;
  m2(1, 1) = 3;
  m2(1, 2) = 5;
  m2(1, 3) = 0;

  m1.MulMatrix(m2);

  EXPECT_EQ(m1(1, 3), 10);
}

TEST(MulMatrixTest, Operator) {
  S21Matrix m1(2, 2);
  S21Matrix m2(2, 4);

  m1(0, 0) = 0;
  m1(0, 1) = 1;
  m1(1, 0) = 2;
  m1(1, 1) = 3;

  m2(0, 0) = 0;
  m2(0, 1) = 1;
  m2(0, 2) = 0;
  m2(0, 3) = 5;
  m2(1, 0) = 2;
  m2(1, 1) = 3;
  m2(1, 2) = 5;
  m2(1, 3) = 0;

  double res = (m1 * m2)(1, 3);

  EXPECT_EQ(res, 10);
}

TEST(MulMatrixTest, Assignment) {
  S21Matrix m1(2, 2);
  S21Matrix m2(2, 4);

  m1(0, 0) = 0;
  m1(0, 1) = 1;
  m1(1, 0) = 2;
  m1(1, 1) = 3;

  m2(0, 0) = 0;
  m2(0, 1) = 1;
  m2(0, 2) = 0;
  m2(0, 3) = 5;
  m2(1, 0) = 2;
  m2(1, 1) = 3;
  m2(1, 2) = 5;
  m2(1, 3) = 0;

  m1 *= m2;

  EXPECT_EQ(m1(1, 3), 10);
}

TEST(TransposeTest, Transpose) {
  S21Matrix m1(3, 2);
  S21Matrix m2(2, 3);

  m1(0, 0) = 1;
  m1(0, 1) = 4;
  m1(1, 0) = 2;
  m1(1, 1) = 5;
  m1(2, 0) = 3;
  m1(2, 1) = 6;

  m2(0, 0) = 1;
  m2(0, 1) = 2;
  m2(0, 2) = 3;
  m2(1, 0) = 4;
  m2(1, 1) = 5;
  m2(1, 2) = 6;

  bool res = m1.Transpose() == m2;

  EXPECT_EQ(res, true);
}

TEST(ComplementsTest, ComplementsMatrix) {
  S21Matrix m1(3, 3);
  S21Matrix m2(3, 3);

  m1(0, 0) = 1;
  m1(0, 1) = 2;
  m1(0, 2) = 3;
  m1(1, 0) = 0;
  m1(1, 1) = 4;
  m1(1, 2) = 2;
  m1(2, 0) = 5;
  m1(2, 1) = 2;
  m1(2, 2) = 1;

  m2(0, 0) = 0;
  m2(0, 1) = 10;
  m2(0, 2) = -20;
  m2(1, 0) = 4;
  m2(1, 1) = -14;
  m2(1, 2) = 8;
  m2(2, 0) = -8;
  m2(2, 1) = -2;
  m2(2, 2) = 4;

  bool res = m1.CalcComplements() == m2;

  EXPECT_EQ(res, true);
}

TEST(ComplementsTest, ComplementsOneMatrix) {
  S21Matrix m(1, 1);
  m(0, 0) = 5;

  double res = (m.CalcComplements())(0, 0);

  EXPECT_EQ(res, 1);
}

TEST(DeterminantTest, Determinant) {
  S21Matrix m(3, 3);

  m(0, 0) = 1;
  m(0, 1) = 2;
  m(0, 2) = 3;
  m(1, 0) = 4;
  m(1, 1) = 5;
  m(1, 2) = 6;
  m(2, 0) = 7;
  m(2, 1) = 8;
  m(2, 2) = 9;

  double res = m.Determinant();

  EXPECT_EQ(res, 0);
}

TEST(DeterminantTest, OneMatr) {
  S21Matrix m(1, 1);

  m(0, 0) = 1;

  double res = m.Determinant();

  EXPECT_EQ(res, 1);
}

TEST(InverseMatrixTest, InverseMatrix) {
  S21Matrix m1(3, 3);
  S21Matrix m2(3, 3);

  m1(0, 0) = 2;
  m1(0, 1) = 5;
  m1(0, 2) = 7;
  m1(1, 0) = 6;
  m1(1, 1) = 3;
  m1(1, 2) = 4;
  m1(2, 0) = 5;
  m1(2, 1) = -2;
  m1(2, 2) = -3;

  m2(0, 0) = 1;
  m2(0, 1) = -1;
  m2(0, 2) = 1;
  m2(1, 0) = -38;
  m2(1, 1) = 41;
  m2(1, 2) = -34;
  m2(2, 0) = 27;
  m2(2, 1) = -29;
  m2(2, 2) = 24;

  bool res = m1.InverseMatrix() == m2;

  EXPECT_EQ(res, true);
}

TEST(AccessorTest, GetRows) {
  S21Matrix m(3, 3);
  int res = m.GetRows();
  EXPECT_EQ(res, 3);
}

TEST(AccessorTest, GetCols) {
  S21Matrix m(3, 3);
  int res = m.GetCols();
  EXPECT_EQ(res, 3);
}

TEST(CopyTest, Copy) {
  S21Matrix m1(2, 2);
  S21Matrix m2(3, 3);
  m1 = m2;
  EXPECT_EQ(m1, m2);
}

TEST(MoveTest, Move) {
  S21Matrix m1(2, 2);
  S21Matrix m2 = std::move(m1);
  EXPECT_EQ(m2(0, 0), 0);
}

TEST(SetRowsTest, SetRows) {
  S21Matrix m(2, 2);
  m.SetRows(1);
  int res = m.GetRows();
  EXPECT_EQ(res, 1);
}