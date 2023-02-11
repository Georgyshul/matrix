#include "s21_matrix.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int _same_size(matrix_t *A, matrix_t *B) {
  return (A->rows == B->rows && A->columns == B->columns) ? 0 : 2;
}

double _calc_minor(matrix_t *A, int row, int column) {
  double result = 0;

  if (A->rows == 1) {
    result = 1;
  } else {
    matrix_t tmp_matrix;
    s21_create_matrix(A->rows - 1, A->columns - 1, &tmp_matrix);

    int row_shift = 0;
    for (int i = 0; i < tmp_matrix.rows; i++) {
      int column_shift = 0;

      if (i >= row) {
        row_shift = 1;
      }

      for (int j = 0; j < tmp_matrix.columns; j++) {

        if (j >= column) {
          column_shift = 1;
        }

        tmp_matrix.matrix[i][j] = A->matrix[i + row_shift][j + column_shift];
      }
    }

    for (int i = 0; i < tmp_matrix.columns; i++) {
      result +=
          tmp_matrix.matrix[0][i] * pow(-1, i) * _calc_minor(&tmp_matrix, 0, i);
    }
    s21_remove_matrix(&tmp_matrix);
  }
  return result;
}