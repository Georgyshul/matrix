#include "s21_matrix.h"

int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  matrix_t T;
  int mult_flag = s21_mult_number(B, -1.0, &T);
  int sum_flag = 2;

  if (!mult_flag) {
    sum_flag = s21_sum_matrix(A, &T, result);
  }
  return sum_flag;
}