#include "s21_matrix.h"
#include <stdio.h>

int s21_inverse_matrix(matrix_t *A, matrix_t *result) {
  double det;
  int flag = s21_determinant(A, &det);

  if (det == 0) {
    flag = 2;
  }

  if (!flag) {
    matrix_t tmp;
    s21_calc_complements(A, &tmp);

    matrix_t transposed;
    s21_transpose(&tmp, &transposed);

    double multiplicant = 1 / det;
    s21_mult_number(&transposed, multiplicant, result);

    s21_remove_matrix(&tmp);
    s21_remove_matrix(&transposed);
  }
  return flag;
}