#include <check.h>
#include <limits.h>
#include <math.h>
#include <stdio.h>

#include "../s21_matrix.h"

int assert_free_matrix(matrix_t *result) {
  int flag = 0;

  if (result->columns == 0 && result->rows == 0 && result->matrix == NULL) {
    flag = 1;
  }

  return flag;
}

START_TEST(creation_1) {
  int rows = 2;
  int columns = 2;
  matrix_t result;

  int flag = s21_create_matrix(rows, columns, &result);

  ck_assert_int_eq(0, flag);
}
END_TEST

START_TEST(creation_2) {
  int rows = 0;
  int columns = 2;
  matrix_t result;

  int flag = s21_create_matrix(rows, columns, &result);

  ck_assert_int_eq(1, flag);
}
END_TEST

START_TEST(remove_1) {
  int rows = 2;
  int columns = 2;
  matrix_t result;

  s21_create_matrix(rows, columns, &result);
  s21_remove_matrix(&result);

  int flag = assert_free_matrix(&result);

  ck_assert_int_eq(1, flag);
}
END_TEST

START_TEST(remove_2) {
  int rows = 0;
  int columns = 2;
  matrix_t result;

  s21_create_matrix(rows, columns, &result);
  s21_remove_matrix(&result);

  int flag = assert_free_matrix(&result);

  ck_assert_int_eq(1, flag);
}
END_TEST

START_TEST(eq_1) {
  int rows = 4;
  int columns = 4;
  matrix_t result_1;
  matrix_t result_2;

  s21_create_matrix(rows, columns, &result_1);
  s21_create_matrix(rows, columns, &result_2);

  double number = 1;

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      result_1.matrix[i][j] = number;
      result_2.matrix[i][j] = number;

      number++;
    }
  }

  int flag = s21_eq_matrix(&result_1, &result_2);

  ck_assert_int_eq(1, flag);
}
END_TEST

START_TEST(eq_2) {
  int rows = 4;
  int columns = 4;
  matrix_t result_1;
  matrix_t result_2;

  s21_create_matrix(rows, columns, &result_1);
  s21_create_matrix(rows, columns, &result_2);

  double number = 1;

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      result_1.matrix[i][j] = number + 1e-7;
      result_2.matrix[i][j] = number;

      number++;
    }
  }

  int flag = s21_eq_matrix(&result_1, &result_2);

  ck_assert_int_eq(0, flag);
}
END_TEST

START_TEST(eq_3) {
  int rows = 4;
  int columns = 4;
  matrix_t result_1;
  matrix_t result_2;

  s21_create_matrix(rows, columns, &result_1);
  s21_create_matrix(rows, columns, &result_2);

  double number = 1;

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      result_1.matrix[i][j] = number + 1e-8;
      result_2.matrix[i][j] = number;

      number++;
    }
  }

  int flag = s21_eq_matrix(&result_1, &result_2);

  ck_assert_int_eq(1, flag);
}
END_TEST

START_TEST(eq_4) {
  int rows_1 = 4;
  int columns_1 = 4;

  int rows_2 = 4;
  int columns_2 = 2;

  matrix_t result_1;
  matrix_t result_2;

  s21_create_matrix(rows_1, columns_1, &result_1);
  s21_create_matrix(rows_2, columns_2, &result_2);

  double number_1 = 1;
  double number_2 = 1;

  for (int i = 0; i < rows_1; i++) {
    for (int j = 0; j < columns_1; j++) {
      result_1.matrix[i][j] = number_1;
      number_1++;
    }
  }

  for (int i = 0; i < rows_2; i++) {
    for (int j = 0; j < columns_2; j++) {
      result_2.matrix[i][j] = number_2;
      number_2++;
    }
  }

  int flag = s21_eq_matrix(&result_1, &result_2);

  ck_assert_int_eq(0, flag);
}
END_TEST

START_TEST(eq_5) {
  int rows_1 = 0;
  int columns_1 = 4;

  int rows_2 = 4;
  int columns_2 = -1;

  matrix_t result_1;
  matrix_t result_2;

  s21_create_matrix(rows_1, columns_1, &result_1);
  s21_create_matrix(rows_2, columns_2, &result_2);

  double number_1 = 1;
  double number_2 = 1;

  for (int i = 0; i < rows_1; i++) {
    for (int j = 0; j < columns_1; j++) {
      result_1.matrix[i][j] = number_1;
      number_1++;
    }
  }

  for (int i = 0; i < rows_2; i++) {
    for (int j = 0; j < columns_2; j++) {
      result_2.matrix[i][j] = number_2;
      number_2++;
    }
  }

  int flag = s21_eq_matrix(&result_1, &result_2);

  ck_assert_int_eq(1, flag);
}
END_TEST

START_TEST(eq_6) {
  int rows_1 = 4;
  int columns_1 = 4;

  int rows_2 = 4;
  int columns_2 = -1;

  matrix_t result_1;
  matrix_t result_2;

  s21_create_matrix(rows_1, columns_1, &result_1);
  s21_create_matrix(rows_2, columns_2, &result_2);

  double number_1 = 1;
  double number_2 = 1;

  for (int i = 0; i < rows_1; i++) {
    for (int j = 0; j < columns_1; j++) {
      result_1.matrix[i][j] = number_1;
      number_1++;
    }
  }

  for (int i = 0; i < rows_2; i++) {
    for (int j = 0; j < columns_2; j++) {
      result_2.matrix[i][j] = number_2;
      number_2++;
    }
  }

  int flag = s21_eq_matrix(&result_1, &result_2);

  ck_assert_int_eq(0, flag);
}
END_TEST

START_TEST(sum_1) {
  int rows_1 = 2;
  int columns_1 = 2;

  int rows_2 = 2;
  int columns_2 = 2;

  matrix_t matrix_1;
  matrix_t matrix_2;

  s21_create_matrix(rows_1, columns_1, &matrix_1);
  s21_create_matrix(rows_2, columns_2, &matrix_2);

  double number_1 = 1;
  double number_2 = 1;

  for (int i = 0; i < rows_1; i++) {
    for (int j = 0; j < columns_1; j++) {
      matrix_1.matrix[i][j] = number_1;
      number_1++;
    }
  }

  for (int i = 0; i < rows_2; i++) {
    for (int j = 0; j < columns_2; j++) {
      matrix_2.matrix[i][j] = number_2;
      number_2++;
    }
  }

  matrix_t result;

  int flag = s21_sum_matrix(&matrix_1, &matrix_2, &result);

  int rows = 2;
  int columns = 2;

  matrix_t true_result;
  s21_create_matrix(rows, columns, &true_result);

  int number = 1;

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      true_result.matrix[i][j] = number * 2;
      number++;
    }
  }

  if (!flag) {
    flag = s21_eq_matrix(&result, &true_result);
  }

  ck_assert_int_eq(1, flag);
}
END_TEST

START_TEST(sum_2) {
  int rows_1 = 2;
  int columns_1 = 2;

  int rows_2 = 2;
  int columns_2 = 3;

  matrix_t matrix_1;
  matrix_t matrix_2;

  s21_create_matrix(rows_1, columns_1, &matrix_1);
  s21_create_matrix(rows_2, columns_2, &matrix_2);

  double number_1 = 1;
  double number_2 = 1;

  for (int i = 0; i < rows_1; i++) {
    for (int j = 0; j < columns_1; j++) {
      matrix_1.matrix[i][j] = number_1;
      number_1++;
    }
  }

  for (int i = 0; i < rows_2; i++) {
    for (int j = 0; j < columns_2; j++) {
      matrix_2.matrix[i][j] = number_2;
      number_2++;
    }
  }

  matrix_t result;

  int flag = s21_sum_matrix(&matrix_1, &matrix_2, &result);

  ck_assert_int_eq(2, flag);
}
END_TEST

START_TEST(sum_3) {
  int rows_1 = -1;
  int columns_1 = -1;

  int rows_2 = -1;
  int columns_2 = -1;

  matrix_t matrix_1;
  matrix_t matrix_2;

  s21_create_matrix(rows_1, columns_1, &matrix_1);
  s21_create_matrix(rows_2, columns_2, &matrix_2);

  double number_1 = 1;
  double number_2 = 1;

  for (int i = 0; i < matrix_1.rows; i++) {
    for (int j = 0; j < matrix_1.columns; j++) {
      matrix_1.matrix[i][j] = number_1;
      number_1++;
    }
  }

  for (int i = 0; i < matrix_2.rows; i++) {
    for (int j = 0; j < matrix_2.columns; j++) {
      matrix_2.matrix[i][j] = number_2;
      number_2++;
    }
  }

  matrix_t result;

  int flag = s21_sum_matrix(&matrix_1, &matrix_2, &result);

  ck_assert_int_eq(2, flag);
}
END_TEST

START_TEST(sum_4) {
  int rows_1 = -1;
  int columns_1 = -1;

  int rows_2 = -3;
  int columns_2 = -4;

  matrix_t matrix_1;
  matrix_t matrix_2;

  s21_create_matrix(rows_1, columns_1, &matrix_1);
  s21_create_matrix(rows_2, columns_2, &matrix_2);

  double number_1 = 1;
  double number_2 = 1;

  for (int i = 0; i < matrix_1.rows; i++) {
    for (int j = 0; j < matrix_1.columns; j++) {
      matrix_1.matrix[i][j] = number_1;
      number_1++;
    }
  }

  for (int i = 0; i < matrix_2.rows; i++) {
    for (int j = 0; j < matrix_2.columns; j++) {
      matrix_2.matrix[i][j] = number_2;
      number_2++;
    }
  }

  matrix_t result;

  int flag = s21_sum_matrix(&matrix_1, &matrix_2, &result);

  ck_assert_int_eq(2, flag);
}
END_TEST

START_TEST(sub_1) {
  int rows_1 = 5;
  int columns_1 = 5;

  int rows_2 = 5;
  int columns_2 = 5;

  matrix_t matrix_1;
  matrix_t matrix_2;

  s21_create_matrix(rows_1, columns_1, &matrix_1);
  s21_create_matrix(rows_2, columns_2, &matrix_2);

  double number_1 = 1;
  double number_2 = 1;

  for (int i = 0; i < matrix_1.rows; i++) {
    for (int j = 0; j < matrix_1.columns; j++) {
      matrix_1.matrix[i][j] = number_1 * 2;
      number_1++;
    }
  }

  for (int i = 0; i < matrix_2.rows; i++) {
    for (int j = 0; j < matrix_2.columns; j++) {
      matrix_2.matrix[i][j] = number_2;
      number_2++;
    }
  }

  matrix_t result;

  int flag = s21_sub_matrix(&matrix_1, &matrix_2, &result);

  int rows = 5;
  int columns = 5;

  matrix_t true_result;
  s21_create_matrix(rows, columns, &true_result);

  int number = 1;

  for (int i = 0; i < true_result.rows; i++) {
    for (int j = 0; j < true_result.columns; j++) {
      true_result.matrix[i][j] = number;
      number++;
    }
  }

  if (!flag) {
    flag = s21_eq_matrix(&result, &true_result);
  }

  ck_assert_int_eq(1, flag);
}
END_TEST

START_TEST(sub_2) {
  int rows_1 = 2;
  int columns_1 = 2;

  int rows_2 = 2;
  int columns_2 = 3;

  matrix_t matrix_1;
  matrix_t matrix_2;

  s21_create_matrix(rows_1, columns_1, &matrix_1);
  s21_create_matrix(rows_2, columns_2, &matrix_2);

  double number_1 = 1;
  double number_2 = 1;

  for (int i = 0; i < rows_1; i++) {
    for (int j = 0; j < columns_1; j++) {
      matrix_1.matrix[i][j] = number_1;
      number_1++;
    }
  }

  for (int i = 0; i < rows_2; i++) {
    for (int j = 0; j < columns_2; j++) {
      matrix_2.matrix[i][j] = number_2;
      number_2++;
    }
  }

  matrix_t result;

  int flag = s21_sub_matrix(&matrix_1, &matrix_2, &result);

  ck_assert_int_eq(2, flag);
}
END_TEST

START_TEST(sub_3) {
  int rows_1 = -1;
  int columns_1 = -1;

  int rows_2 = -1;
  int columns_2 = -1;

  matrix_t matrix_1;
  matrix_t matrix_2;

  s21_create_matrix(rows_1, columns_1, &matrix_1);
  s21_create_matrix(rows_2, columns_2, &matrix_2);

  double number_1 = 1;
  double number_2 = 1;

  for (int i = 0; i < matrix_1.rows; i++) {
    for (int j = 0; j < matrix_1.columns; j++) {
      matrix_1.matrix[i][j] = number_1;
      number_1++;
    }
  }

  for (int i = 0; i < matrix_2.rows; i++) {
    for (int j = 0; j < matrix_2.columns; j++) {
      matrix_2.matrix[i][j] = number_2;
      number_2++;
    }
  }

  matrix_t result;

  int flag = s21_sub_matrix(&matrix_1, &matrix_2, &result);

  ck_assert_int_eq(2, flag);
}
END_TEST

START_TEST(sub_4) {
  int rows_1 = -1;
  int columns_1 = -1;

  int rows_2 = -3;
  int columns_2 = -4;

  matrix_t matrix_1;
  matrix_t matrix_2;

  s21_create_matrix(rows_1, columns_1, &matrix_1);
  s21_create_matrix(rows_2, columns_2, &matrix_2);

  double number_1 = 1;
  double number_2 = 1;

  for (int i = 0; i < matrix_1.rows; i++) {
    for (int j = 0; j < matrix_1.columns; j++) {
      matrix_1.matrix[i][j] = number_1;
      number_1++;
    }
  }

  for (int i = 0; i < matrix_2.rows; i++) {
    for (int j = 0; j < matrix_2.columns; j++) {
      matrix_2.matrix[i][j] = number_2;
      number_2++;
    }
  }

  matrix_t result;

  int flag = s21_sub_matrix(&matrix_1, &matrix_2, &result);

  ck_assert_int_eq(2, flag);
}
END_TEST

START_TEST(mult_number_1) {
  int rows = 5;
  int columns = 5;
  matrix_t matrix;
  matrix_t result;

  double counter = 0;

  s21_create_matrix(rows, columns, &matrix);
  for (int i = 0; i < matrix.rows; i++) {
    for (int j = 0; j < matrix.columns; j++) {
      matrix.matrix[i][j] = counter;
      counter++;
    }
  }
  double number = 2.5;

  int mult_flag = s21_mult_number(&matrix, number, &result);

  matrix_t true_result;
  s21_create_matrix(rows, columns, &true_result);

  counter = 0;
  for (int i = 0; i < true_result.rows; i++) {
    for (int j = 0; j < true_result.columns; j++) {
      true_result.matrix[i][j] = counter * number;
      counter++;
    }
  }

  int flag = 1;

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      if (result.matrix[i][j] != true_result.matrix[i][j]) {
        flag = 0;
      }
    }
  }

  ck_assert_int_eq(1, flag);
}
END_TEST

START_TEST(mult_number_2) {
  int rows = 0;
  int columns = 5;
  matrix_t matrix;
  matrix_t result;

  double counter = 0;

  s21_create_matrix(rows, columns, &matrix);
  for (int i = 0; i < matrix.rows; i++) {
    for (int j = 0; j < matrix.columns; j++) {
      matrix.matrix[i][j] = counter;
      counter++;
    }
  }
  double number = 2.5;

  int mult_flag = s21_mult_number(&matrix, number, &result);

  ck_assert_int_eq(2, mult_flag);
}
END_TEST

START_TEST(mult_matrix_1) {
  int rows_1 = 3;
  int columns_1 = 1;

  int rows_2 = 1;
  int columns_2 = 3;

  matrix_t matrix_1;
  matrix_t matrix_2;

  s21_create_matrix(rows_1, columns_1, &matrix_1);
  s21_create_matrix(rows_2, columns_2, &matrix_2);

  double number_1 = 1;
  double number_2 = 4;

  for (int i = 0; i < matrix_1.rows; i++) {
    for (int j = 0; j < matrix_1.columns; j++) {
      matrix_1.matrix[i][j] = number_1;
      number_1++;
    }
  }

  for (int i = 0; i < matrix_2.rows; i++) {
    for (int j = 0; j < matrix_2.columns; j++) {
      matrix_2.matrix[i][j] = number_2;
      number_2++;
    }
  }

  matrix_t result;

  int flag = s21_mult_matrix(&matrix_1, &matrix_2, &result);

  int rows = 3;
  int columns = 3;

  matrix_t true_result;
  s21_create_matrix(rows, columns, &true_result);

  int multiplicant = 1;

  for (int i = 0; i < true_result.rows; i++) {
    int number = 4;
    for (int j = 0; j < true_result.columns; j++) {
      true_result.matrix[i][j] = number * multiplicant;
      number++;
    }
    multiplicant++;
  }

  if (!flag) {
    flag = s21_eq_matrix(&result, &true_result);
  }

  ck_assert_int_eq(1, flag);
}
END_TEST

START_TEST(mult_matrix_2) {
  int rows_1 = 3;
  int columns_1 = 2;

  int rows_2 = 2;
  int columns_2 = 3;

  matrix_t matrix_1;
  matrix_t matrix_2;

  s21_create_matrix(rows_1, columns_1, &matrix_1);
  s21_create_matrix(rows_2, columns_2, &matrix_2);

  double number_1 = 1;
  double number_2 = 1;

  for (int i = 0; i < matrix_1.rows; i++) {
    for (int j = 0; j < matrix_1.columns; j++) {
      matrix_1.matrix[i][j] = number_1;
      number_1++;
    }
  }

  for (int i = 0; i < matrix_2.rows; i++) {
    for (int j = 0; j < matrix_2.columns; j++) {
      matrix_2.matrix[i][j] = number_2;
    }
  }

  matrix_t result;

  int flag = s21_mult_matrix(&matrix_1, &matrix_2, &result);

  int rows = 3;
  int columns = 3;

  matrix_t true_result;
  s21_create_matrix(rows, columns, &true_result);

  int number = 1;

  for (int i = 0; i < true_result.rows; i++) {
    for (int j = 0; j < true_result.columns; j++) {
      true_result.matrix[i][j] = number * 2 + 1;
    }
    number += 2;
  }

  if (!flag) {
    flag = s21_eq_matrix(&result, &true_result);
  }

  ck_assert_int_eq(1, flag);
}
END_TEST

START_TEST(mult_matrix_3) {
  int rows_1 = 3;
  int columns_1 = 1;

  int rows_2 = 2;
  int columns_2 = 3;

  matrix_t matrix_1;
  matrix_t matrix_2;

  s21_create_matrix(rows_1, columns_1, &matrix_1);
  s21_create_matrix(rows_2, columns_2, &matrix_2);

  double number_1 = 1;
  double number_2 = 4;

  for (int i = 0; i < matrix_1.rows; i++) {
    for (int j = 0; j < matrix_1.columns; j++) {
      matrix_1.matrix[i][j] = number_1;
      number_1++;
    }
  }

  for (int i = 0; i < matrix_2.rows; i++) {
    for (int j = 0; j < matrix_2.columns; j++) {
      matrix_2.matrix[i][j] = number_2;
      number_2++;
    }
  }

  matrix_t result;

  int flag = s21_mult_matrix(&matrix_1, &matrix_2, &result);

  ck_assert_int_eq(2, flag);
}
END_TEST

START_TEST(mult_matrix_4) {
  int rows_1 = 3;
  int columns_1 = 1;

  int rows_2 = 2;
  int columns_2 = 0;

  matrix_t matrix_1;
  matrix_t matrix_2;

  s21_create_matrix(rows_1, columns_1, &matrix_1);
  s21_create_matrix(rows_2, columns_2, &matrix_2);

  double number_1 = 1;
  double number_2 = 4;

  for (int i = 0; i < matrix_1.rows; i++) {
    for (int j = 0; j < matrix_1.columns; j++) {
      matrix_1.matrix[i][j] = number_1;
      number_1++;
    }
  }

  for (int i = 0; i < matrix_2.rows; i++) {
    for (int j = 0; j < matrix_2.columns; j++) {
      matrix_2.matrix[i][j] = number_2;
      number_2++;
    }
  }

  matrix_t result;

  int flag = s21_mult_matrix(&matrix_1, &matrix_2, &result);

  ck_assert_int_eq(2, flag);
}
END_TEST

START_TEST(mult_matrix_5) {
  int rows_1 = 3;
  int columns_1 = 0;

  int rows_2 = 2;
  int columns_2 = 0;

  matrix_t matrix_1;
  matrix_t matrix_2;

  s21_create_matrix(rows_1, columns_1, &matrix_1);
  s21_create_matrix(rows_2, columns_2, &matrix_2);

  double number_1 = 1;
  double number_2 = 4;

  for (int i = 0; i < matrix_1.rows; i++) {
    for (int j = 0; j < matrix_1.columns; j++) {
      matrix_1.matrix[i][j] = number_1;
      number_1++;
    }
  }

  for (int i = 0; i < matrix_2.rows; i++) {
    for (int j = 0; j < matrix_2.columns; j++) {
      matrix_2.matrix[i][j] = number_2;
      number_2++;
    }
  }

  matrix_t result;

  int flag = s21_mult_matrix(&matrix_1, &matrix_2, &result);

  ck_assert_int_eq(1, flag);
}
END_TEST

START_TEST(transpose_1) {
  int rows_1 = 3;
  int columns_1 = 3;

  matrix_t matrix_1;

  s21_create_matrix(rows_1, columns_1, &matrix_1);

  double number_1 = 1;

  for (int i = 0; i < matrix_1.rows; i++) {
    for (int j = 0; j < matrix_1.columns; j++) {
      matrix_1.matrix[i][j] = number_1;
      number_1++;
    }
  }

  matrix_t result;

  int flag = s21_transpose(&matrix_1, &result);

  int rows = 3;
  int columns = 3;

  matrix_t true_result;
  s21_create_matrix(rows, columns, &true_result);

  int number = 1;

  for (int i = 0; i < true_result.columns; i++) {
    for (int j = 0; j < true_result.rows; j++) {
      true_result.matrix[j][i] = number;
      number++;
    }
  }

  if (!flag) {
    flag = s21_eq_matrix(&result, &true_result);
  }

  ck_assert_int_eq(1, flag);
}
END_TEST

START_TEST(transpose_2) {
  int rows_1 = 3;
  int columns_1 = 2;

  matrix_t matrix_1;

  s21_create_matrix(rows_1, columns_1, &matrix_1);

  double number_1 = 1;

  for (int i = 0; i < matrix_1.rows; i++) {
    for (int j = 0; j < matrix_1.columns; j++) {
      matrix_1.matrix[i][j] = number_1;
      number_1++;
    }
  }

  matrix_t result;

  int flag = s21_transpose(&matrix_1, &result);

  ck_assert_int_eq(2, flag);
}
END_TEST

START_TEST(transpose_3) {
  int rows_1 = 3;
  int columns_1 = 0;

  matrix_t matrix_1;

  s21_create_matrix(rows_1, columns_1, &matrix_1);

  double number_1 = 1;

  for (int i = 0; i < matrix_1.rows; i++) {
    for (int j = 0; j < matrix_1.columns; j++) {
      matrix_1.matrix[i][j] = number_1;
      number_1++;
    }
  }

  matrix_t result;

  int flag = s21_transpose(&matrix_1, &result);

  ck_assert_int_eq(1, flag);
}
END_TEST

START_TEST(transpose_4) {
  int rows_1 = 15;
  int columns_1 = 15;

  matrix_t matrix_1;

  s21_create_matrix(rows_1, columns_1, &matrix_1);

  double number_1 = 1;

  for (int i = 0; i < matrix_1.rows; i++) {
    for (int j = 0; j < matrix_1.columns; j++) {
      matrix_1.matrix[i][j] = number_1;
      number_1++;
    }
  }

  matrix_t result;

  int flag = s21_transpose(&matrix_1, &result);

  int rows = 15;
  int columns = 15;

  matrix_t true_result;
  s21_create_matrix(rows, columns, &true_result);

  int number = 1;

  for (int i = 0; i < true_result.columns; i++) {
    for (int j = 0; j < true_result.rows; j++) {
      true_result.matrix[j][i] = number;
      number++;
    }
  }

  if (!flag) {
    flag = s21_eq_matrix(&result, &true_result);
  }

  ck_assert_int_eq(1, flag);
}
END_TEST

START_TEST(calc_complements_1) {
  int rows_1 = 2;
  int columns_1 = 2;

  matrix_t matrix_1;

  s21_create_matrix(rows_1, columns_1, &matrix_1);

  double number_1 = 1;

  for (int i = 0; i < matrix_1.rows; i++) {
    for (int j = 0; j < matrix_1.columns; j++) {
      matrix_1.matrix[i][j] = number_1;
      number_1++;
    }
  }

  matrix_t result;

  int flag = s21_calc_complements(&matrix_1, &result);

  int rows = 2;
  int columns = 2;

  matrix_t true_result;
  s21_create_matrix(rows, columns, &true_result);

  true_result.matrix[0][0] = 4;
  true_result.matrix[0][1] = -3;
  true_result.matrix[1][0] = -2;
  true_result.matrix[1][1] = 1;

  // for (int i = 0; i < result.rows; i++) {
  //   for (int j = 0; j < result.columns; j++) {
  //     printf("%lf ", result.matrix[i][j]);
  //   }
  //   printf("\n");
  // }

  if (!flag) {
    flag = s21_eq_matrix(&result, &true_result);
  }

  ck_assert_int_eq(1, flag);
}
END_TEST

START_TEST(calc_complements_2) {
  int rows_1 = 3;
  int columns_1 = 3;

  matrix_t matrix_1;

  s21_create_matrix(rows_1, columns_1, &matrix_1);

  double number_1 = 1;

  for (int i = 0; i < matrix_1.rows; i++) {
    for (int j = 0; j < matrix_1.columns; j++) {
      matrix_1.matrix[i][j] = number_1 * pow(-1, i + j);
      number_1++;
    }
  }

  matrix_t result;

  int flag = s21_calc_complements(&matrix_1, &result);

  int rows = 3;
  int columns = 3;

  matrix_t true_result;
  s21_create_matrix(rows, columns, &true_result);

  true_result.matrix[0][0] = -3;
  true_result.matrix[0][1] = -6;
  true_result.matrix[0][2] = -3;
  true_result.matrix[1][0] = -6;
  true_result.matrix[1][1] = -12;
  true_result.matrix[1][2] = -6;
  true_result.matrix[2][0] = -3;
  true_result.matrix[2][1] = -6;
  true_result.matrix[2][2] = -3;

  // for (int i = 0; i < result.rows; i++) {
  //   for (int j = 0; j < result.columns; j++) {
  //     printf("%lf ", result.matrix[i][j]);
  //   }
  //   printf("\n");
  // }

  if (!flag) {
    flag = s21_eq_matrix(&result, &true_result);
  }

  ck_assert_int_eq(1, flag);
}
END_TEST

START_TEST(calc_complements_3) {
  int rows_1 = 1;
  int columns_1 = 2;

  matrix_t matrix_1;

  s21_create_matrix(rows_1, columns_1, &matrix_1);

  double number_1 = 1;

  for (int i = 0; i < matrix_1.rows; i++) {
    for (int j = 0; j < matrix_1.columns; j++) {
      matrix_1.matrix[i][j] = number_1;
      number_1++;
    }
  }

  matrix_t result;

  int flag = s21_calc_complements(&matrix_1, &result);

  ck_assert_int_eq(2, flag);
}
END_TEST

START_TEST(calc_complements_4) {
  int rows_1 = 0;
  int columns_1 = 0;

  matrix_t matrix_1;

  s21_create_matrix(rows_1, columns_1, &matrix_1);

  double number_1 = 1;

  for (int i = 0; i < matrix_1.rows; i++) {
    for (int j = 0; j < matrix_1.columns; j++) {
      matrix_1.matrix[i][j] = number_1;
      number_1++;
    }
  }

  matrix_t result;

  int flag = s21_calc_complements(&matrix_1, &result);

  ck_assert_int_eq(1, flag);
}
END_TEST

START_TEST(calc_complements_5) {
  int rows_1 = 1;
  int columns_1 = 1;

  matrix_t matrix_1;

  s21_create_matrix(rows_1, columns_1, &matrix_1);

  double number_1 = 4;

  for (int i = 0; i < matrix_1.rows; i++) {
    for (int j = 0; j < matrix_1.columns; j++) {
      matrix_1.matrix[i][j] = number_1;
      number_1++;
    }
  }

  matrix_t result;

  int flag = s21_calc_complements(&matrix_1, &result);

  int rows = 1;
  int columns = 1;

  matrix_t true_result;
  s21_create_matrix(rows, columns, &true_result);

  true_result.matrix[0][0] = 1;

  if (!flag) {
    flag = s21_eq_matrix(&result, &true_result);
  }

  ck_assert_int_eq(1, flag);
}
END_TEST

START_TEST(det_1) {
  int rows_1 = 2;
  int columns_1 = 2;

  matrix_t matrix_1;

  s21_create_matrix(rows_1, columns_1, &matrix_1);

  double number_1 = 1;

  for (int i = 0; i < matrix_1.rows; i++) {
    for (int j = 0; j < matrix_1.columns; j++) {
      matrix_1.matrix[i][j] = number_1;
      number_1++;
    }
  }

  double result;

  int flag = s21_determinant(&matrix_1, &result);

  double true_result = -2;

  if (result == true_result) {
    flag = 1;
  }

  ck_assert_int_eq(1, flag);
}
END_TEST

START_TEST(det_2) {
  int rows_1 = 5;
  int columns_1 = 5;

  matrix_t matrix_1;

  s21_create_matrix(rows_1, columns_1, &matrix_1);

  double number_1 = 1;

  for (int i = 0; i < matrix_1.rows; i++) {
    for (int j = 0; j < matrix_1.columns; j++) {
      matrix_1.matrix[i][j] = number_1;
      number_1++;
    }
  }

  double result;

  int flag = s21_determinant(&matrix_1, &result);

  double true_result = 0.0;

  if (fabs(result - true_result) < 1e-6) {
    flag = 1;
  }

  ck_assert_int_eq(1, flag);
}
END_TEST

START_TEST(det_3) {
  int rows_1 = 3;
  int columns_1 = 3;

  matrix_t matrix_1;

  s21_create_matrix(rows_1, columns_1, &matrix_1);

  matrix_1.matrix[0][0] = 2;
  matrix_1.matrix[0][1] = 5;
  matrix_1.matrix[0][2] = 7;
  matrix_1.matrix[1][0] = 6;
  matrix_1.matrix[1][1] = 3;
  matrix_1.matrix[1][2] = 4;
  matrix_1.matrix[2][0] = 5;
  matrix_1.matrix[2][1] = -2;
  matrix_1.matrix[2][2] = -3;

  double result;

  int flag = s21_determinant(&matrix_1, &result);

  double true_result = -1;

  if (result == true_result) {
    flag = 1;
  }

  ck_assert_int_eq(1, flag);
}
END_TEST

START_TEST(det_4) {
  int rows_1 = 2;
  int columns_1 = 5;

  matrix_t matrix_1;

  s21_create_matrix(rows_1, columns_1, &matrix_1);

  double number_1 = 1;

  for (int i = 0; i < matrix_1.rows; i++) {
    for (int j = 0; j < matrix_1.columns; j++) {
      matrix_1.matrix[i][j] = number_1;
      number_1++;
    }
  }

  double result;

  int flag = s21_determinant(&matrix_1, &result);

  ck_assert_int_eq(2, flag);
}
END_TEST

START_TEST(det_5) {
  int rows_1 = 0;
  int columns_1 = 0;

  matrix_t matrix_1;

  s21_create_matrix(rows_1, columns_1, &matrix_1);

  double number_1 = 1;

  for (int i = 0; i < matrix_1.rows; i++) {
    for (int j = 0; j < matrix_1.columns; j++) {
      matrix_1.matrix[i][j] = number_1;
      number_1++;
    }
  }

  double result;

  int flag = s21_determinant(&matrix_1, &result);

  ck_assert_int_eq(2, flag);
}
END_TEST

START_TEST(inverse_1) {
  int rows_1 = 3;
  int columns_1 = 3;

  matrix_t matrix_1;

  s21_create_matrix(rows_1, columns_1, &matrix_1);

  matrix_1.matrix[0][0] = 2;
  matrix_1.matrix[0][1] = 5;
  matrix_1.matrix[0][2] = 7;
  matrix_1.matrix[1][0] = 6;
  matrix_1.matrix[1][1] = 3;
  matrix_1.matrix[1][2] = 4;
  matrix_1.matrix[2][0] = 5;
  matrix_1.matrix[2][1] = -2;
  matrix_1.matrix[2][2] = -3;

  matrix_t result;

  int flag = s21_inverse_matrix(&matrix_1, &result);

  int rows = 3;
  int columns = 3;

  matrix_t true_result;
  s21_create_matrix(rows, columns, &true_result);

  true_result.matrix[0][0] = 1;
  true_result.matrix[0][1] = -1;
  true_result.matrix[0][2] = 1;
  true_result.matrix[1][0] = -38;
  true_result.matrix[1][1] = 41;
  true_result.matrix[1][2] = -34;
  true_result.matrix[2][0] = 27;
  true_result.matrix[2][1] = -29;
  true_result.matrix[2][2] = 24;

  // for (int i = 0; i < result.rows; i++) {
  //   for (int j = 0; j < result.columns; j++) {
  //     printf("%lf ", result.matrix[i][j]);
  //   }
  //   printf("\n");
  // }

  // for (int i = 0; i < true_result.rows; i++) {
  //   for (int j = 0; j < true_result.columns; j++) {
  //     printf("%lf ", true_result.matrix[i][j]);
  //   }
  //   printf("\n");
  // }

  if (!flag) {
    flag = s21_eq_matrix(&result, &true_result);
  }

  ck_assert_int_eq(1, flag);
}
END_TEST

START_TEST(inverse_2) {
  int rows_1 = 3;
  int columns_1 = 3;

  matrix_t matrix_1;

  s21_create_matrix(rows_1, columns_1, &matrix_1);

  matrix_1.matrix[0][0] = 1;
  matrix_1.matrix[0][1] = 2;
  matrix_1.matrix[0][2] = 3;
  matrix_1.matrix[1][0] = 4;
  matrix_1.matrix[1][1] = 5;
  matrix_1.matrix[1][2] = 6;
  matrix_1.matrix[2][0] = 7;
  matrix_1.matrix[2][1] = 8;
  matrix_1.matrix[2][2] = 9;

  matrix_t result;

  int flag = s21_inverse_matrix(&matrix_1, &result);

  ck_assert_int_eq(2, flag);
}
END_TEST

START_TEST(inverse_3) {
  int rows_1 = 2;
  int columns_1 = 3;

  matrix_t matrix_1;

  s21_create_matrix(rows_1, columns_1, &matrix_1);

  double number = 1;
  for (int i = 0; i < matrix_1.rows; i++) {
    for (int j = 0; j < matrix_1.columns; j++) {
      matrix_1.matrix[i][j] = number;
      number++;
    }
  }

  matrix_t result;

  int flag = s21_inverse_matrix(&matrix_1, &result);

  ck_assert_int_eq(2, flag);
}
END_TEST

int main(void) {
  Suite *s1 = suite_create("Core");
  SRunner *sr = srunner_create(s1);
  int nf;

  TCase *s21_create_matrix = tcase_create("creation");
  suite_add_tcase(s1, s21_create_matrix);
  tcase_add_test(s21_create_matrix, creation_1);
  tcase_add_test(s21_create_matrix, creation_2);

  TCase *s21_remove_matrix = tcase_create("remove");
  suite_add_tcase(s1, s21_remove_matrix);
  tcase_add_test(s21_remove_matrix, remove_1);
  tcase_add_test(s21_remove_matrix, remove_2);

  TCase *s21_eq_matrix = tcase_create("eq");
  suite_add_tcase(s1, s21_eq_matrix);
  tcase_add_test(s21_eq_matrix, eq_1);
  tcase_add_test(s21_eq_matrix, eq_2);
  tcase_add_test(s21_eq_matrix, eq_3);
  tcase_add_test(s21_eq_matrix, eq_4);
  tcase_add_test(s21_eq_matrix, eq_5);
  tcase_add_test(s21_eq_matrix, eq_6);

  TCase *s21_sum_matrix = tcase_create("sum");
  suite_add_tcase(s1, s21_sum_matrix);
  tcase_add_test(s21_sum_matrix, sum_1);
  tcase_add_test(s21_sum_matrix, sum_2);
  tcase_add_test(s21_sum_matrix, sum_3);
  tcase_add_test(s21_sum_matrix, sum_4);

  TCase *s21_sub_matrix = tcase_create("sub");
  suite_add_tcase(s1, s21_sub_matrix);
  tcase_add_test(s21_sub_matrix, sub_1);
  tcase_add_test(s21_sub_matrix, sub_2);
  tcase_add_test(s21_sub_matrix, sub_3);
  tcase_add_test(s21_sub_matrix, sub_4);

  TCase *s21_mult_number = tcase_create("mult_number");
  suite_add_tcase(s1, s21_mult_number);
  tcase_add_test(s21_mult_number, mult_number_1);
  tcase_add_test(s21_mult_number, mult_number_2);

  TCase *s21_mult_matrix = tcase_create("mult_matrix");
  suite_add_tcase(s1, s21_mult_matrix);
  tcase_add_test(s21_mult_matrix, mult_matrix_1);
  tcase_add_test(s21_mult_matrix, mult_matrix_2);
  tcase_add_test(s21_mult_matrix, mult_matrix_3);
  tcase_add_test(s21_mult_matrix, mult_matrix_4);
  tcase_add_test(s21_mult_matrix, mult_matrix_5);

  TCase *s21_transpose = tcase_create("transpose");
  suite_add_tcase(s1, s21_transpose);
  tcase_add_test(s21_transpose, transpose_1);
  tcase_add_test(s21_transpose, transpose_2);
  tcase_add_test(s21_transpose, transpose_3);
  tcase_add_test(s21_transpose, transpose_4);

  TCase *s21_calc_complements = tcase_create("calc_complements");
  suite_add_tcase(s1, s21_calc_complements);
  tcase_add_test(s21_calc_complements, calc_complements_1);
  tcase_add_test(s21_calc_complements, calc_complements_2);
  tcase_add_test(s21_calc_complements, calc_complements_3);
  tcase_add_test(s21_calc_complements, calc_complements_4);
  tcase_add_test(s21_calc_complements, calc_complements_5);

  TCase *s21_determinant = tcase_create("det");
  suite_add_tcase(s1, s21_determinant);
  tcase_add_test(s21_determinant, det_1);
  tcase_add_test(s21_determinant, det_2);
  tcase_add_test(s21_determinant, det_3);
  tcase_add_test(s21_determinant, det_4);
  tcase_add_test(s21_determinant, det_5);

  TCase *s21_inverse = tcase_create("inverse");
  suite_add_tcase(s1, s21_inverse);
  tcase_add_test(s21_inverse, inverse_1);
  tcase_add_test(s21_inverse, inverse_2);
  tcase_add_test(s21_inverse, inverse_3);

  srunner_run_all(sr, CK_ENV);
  nf = srunner_ntests_failed(sr);
  srunner_free(sr);

  return nf == 0 ? 0 : 1;
}
