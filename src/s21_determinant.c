#include "s21_matrix.h"
#include <math.h>

int s21_determinant(matrix_t *A, double *result) {
  int flag = 2;
  if (A->columns == A->rows && A->columns > 0) {
    for (int i = 0; i < A->columns; i++) {
      *result += A->matrix[0][i] * pow(-1, i) * _calc_minor(A, 0, i);
    }
    flag = 0;
  }
  return flag;
}