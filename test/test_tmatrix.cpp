#include "tmatrix.h"

#include <gtest.h>

TEST(TDynamicMatrix, can_create_matrix_with_positive_length)
{
  ASSERT_NO_THROW(TDynamicMatrix<int> m(5));
}

TEST(TDynamicMatrix, cant_create_too_large_matrix)
{
  ASSERT_ANY_THROW(TDynamicMatrix<int> m(MAX_MATRIX_SIZE + 1));
}

TEST(TDynamicMatrix, throws_when_create_matrix_with_negative_length)
{
  ASSERT_ANY_THROW(TDynamicMatrix<int> m(-5));
}

TEST(TDynamicMatrix, can_create_copied_matrix)
{
  TDynamicMatrix<int> m(5);

  ASSERT_NO_THROW(TDynamicMatrix<int> m1(m));
}

TEST(TDynamicMatrix, copied_matrix_is_equal_to_source_one)
{
	TDynamicMatrix<int> m1(4);
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			m1[i][j] = i + j;
		}
	}
	TDynamicMatrix<int> m2(m1);
	EXPECT_EQ(m2[2][0], m1[2][0]);
}

TEST(TDynamicMatrix, copied_matrix_has_its_own_memory)
{
	TDynamicMatrix<int> m1(4);
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			m1[i][j] = i + j;
		}
	}
	TDynamicMatrix<int> m2(m1);
	m2[0][0] = 15;
	EXPECT_NE(m2[0][0], m1[0][0]);
}

TEST(TDynamicMatrix, can_get_size)
{
	TDynamicMatrix<int> v(4);
	EXPECT_EQ(4, v.size());
}

TEST(TDynamicMatrix, can_set_and_get_element)
{
	TDynamicMatrix<int> m(4);
	m[0][0] = 4;
	EXPECT_EQ(4, m[0][0]);
}
TEST(TDynamicMatrix, can_set_and_get_element_with_at)
{
	TDynamicMatrix<int> m(4);
	m.at(0).at(0) = 4;
	EXPECT_EQ(4, m.at(0).at(0));
}

TEST(TDynamicMatrix, throws_when_set_element_with_negative_index)
{
	TDynamicMatrix<int> m(4);
	ASSERT_ANY_THROW(m.at(-1));
}

TEST(TDynamicMatrix, throws_when_set_element_with_too_large_index)
{
	TDynamicMatrix<int> m(4);
	ASSERT_ANY_THROW(m.at(5));
}

TEST(TDynamicMatrix, can_assign_matrix_to_itself)
{
	TDynamicMatrix<int> m(4);
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			m[i][j] = i + j;
		}
	}
	ASSERT_NO_THROW(m = m);
}

TEST(TDynamicMatrix, can_assign_matrices_of_equal_size)
{
	TDynamicMatrix<int> m(4);
	TDynamicMatrix<int> mm(4);
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			m[i][j] = i + j;
			mm[i][j] = i - j;
		}
	}
	mm = m;
	ASSERT_EQ(mm[2][0], m[2][0]);
}

TEST(TDynamicMatrix, assign_operator_change_matrix_size)
{
	TDynamicMatrix<int> m(4);
	TDynamicMatrix<int> mm(3);
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			m[i][j] = i + j;
		}
	}
	mm = m;
	ASSERT_EQ(mm.size(), 4);
}

TEST(TDynamicMatrix, can_assign_matrices_of_different_size)
{
	TDynamicMatrix<int> m(4);
	TDynamicMatrix<int> mm(3);
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			m[i][j] = i + j;
		}
	}
	mm = m;
	ASSERT_EQ(mm[2][0], m[2][0]);
}

TEST(TDynamicMatrix, compare_equal_matrices_return_true)
{
	TDynamicMatrix<int> m(4);
	TDynamicMatrix<int> mm(4);
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			m[i][j] = i + j;
			mm[i][j] = i + j;
		}
	}
	ASSERT_EQ(m==mm, 1);
}

TEST(TDynamicMatrix, compare_matrix_with_itself_return_true)
{
	TDynamicMatrix<int> m(4);
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			m[i][j] = i + j;
		}
	}
	ASSERT_EQ(m == m, 1);
}

TEST(TDynamicMatrix, matrices_with_different_size_are_not_equal)
{
	TDynamicMatrix<int> m(4);
	TDynamicMatrix<int> mm(3);
	ASSERT_EQ(m == mm, 0);
}
TEST(TDynamicMatrix, compare_with_operator_not_equal_equal_matrices_return_false)
{
	TDynamicMatrix<int> m(4);
	TDynamicMatrix<int> mm(4);
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			m[i][j] = i + j;
			mm[i][j] = i + j;
		}
	}
	ASSERT_EQ(m!=mm, 0);
}

TEST(TDynamicMatrix, compare_with_operator_not_equal_matrix_with_itself_return_false)
{
	TDynamicMatrix<int> m(4);
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			m[i][j] = i + j;
		}
	}
	ASSERT_EQ(m != m, 0);
}

TEST(TDynamicMatrix, compare_with_operator_not_equal_matrices_with_different_return_true)
{
	TDynamicMatrix<int> m(4);
	TDynamicMatrix<int> mm(3);
	ASSERT_EQ(m != mm, 1);
}

TEST(TDynamicMatrix, can_add_matrices_with_equal_size)
{
	TDynamicMatrix<int> m(4);
	TDynamicMatrix<int> mm(4);
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			m[i][j] = i + j;
			mm[i][j] = i + j + 1;
		}
	}
	m = m + mm;
	ASSERT_EQ(m[2][3], 11);
}

TEST(TDynamicMatrix, cant_add_matrices_with_not_equal_size)
{
	TDynamicMatrix<int> m(4);
	TDynamicMatrix<int> mm(3);
	ASSERT_ANY_THROW(m+mm);
}

TEST(TDynamicMatrix, can_subtract_matrices_with_equal_size)
{
	TDynamicMatrix<int> m(4);
	TDynamicMatrix<int> mm(4);
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			m[i][j] = i + j;
			mm[i][j] = i + j + 1;
		}
	}
	m = m - mm;
	ASSERT_EQ(m[2][3], -1);
}

TEST(TDynamicMatrix, cant_subtract_matrixes_with_not_equal_size)
{
	TDynamicMatrix<int> m(4);
	TDynamicMatrix<int> mm(3);
	ASSERT_ANY_THROW(m - mm);
}
TEST(TDynamicMatrix, can_multiply_matrix_with_equal_size)
{
	TDynamicMatrix<int> m(4);
	TDynamicMatrix<int> mm(4);
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			m[i][j] = i + j;
			mm[i][j] = i + j + 1;
		}
	}
	m = m * mm;
	ASSERT_EQ(m[2][3], 82);

}

TEST(TDynamicMatrix, cant_multiply_matrix_with_not_equal_size)
{
	TDynamicMatrix<int> m(4);
	TDynamicMatrix<int> mm(3);
	ASSERT_ANY_THROW(m * mm);
}

TEST(TDynamicMatrix, can_multiply_matrix_and_vector_with_equal_size)
{
	TDynamicMatrix<int> m(4);
	TDynamicVector<int> v(4);
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			m[i][j] = i + j;
		}
		v[i] = i;
	}
	v = m * v;
	ASSERT_EQ(v[1], 20);

}

TEST(TDynamicMatrix, cant_multiply_matrix_and_vector_with_not_equal_size)
{
	TDynamicMatrix<int> m(4);
	TDynamicVector<int> v(3);
	ASSERT_ANY_THROW(m * v);
}

TEST(TDynamicMatrix, can_multiply_matrix_and_scalar)
{
	TDynamicMatrix<int> m(4);
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			m[i][j] = i + j;
		}
	}
	m = m * 4;
	ASSERT_EQ(m[1][2], 12);

}


