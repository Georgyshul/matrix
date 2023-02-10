#include "s21_matrix.h"
#include <math.h>

int s21_calc_complements(matrix_t *A, matrix_t *result) {
  int flag = 2;
  if (A->columns == A->rows) {
    flag = s21_create_matrix(A->rows, A->columns, result);
  }

  if (!flag) {
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
        double minor = _calc_minor(A, i, j);
        result->matrix[i][j] = pow(-1, i + j) * minor;
      }
    }
  }
  return flag;
}