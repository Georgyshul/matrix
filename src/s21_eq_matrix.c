#include "s21_matrix.h"
#include <math.h>

int s21_eq_matrix(matrix_t *A, matrix_t *B) {
  int flag = SUCCESS;

  if ((A->rows != B->rows) || (A->columns != B->columns)) {
    flag = FAILURE;
  }

  if (flag) {
    for (int i = 0; i < A->rows && flag; i++) {
      for (int j = 0; j < A->columns && flag; j++) {
        if (fabs(A->matrix[i][j] - B->matrix[i][j]) >= EPS) {
          flag = FAILURE;
        }
      }
    }
  }
  return flag;
}