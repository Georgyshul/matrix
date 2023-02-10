#include "s21_matrix.h"
#include <stdlib.h>

int s21_create_matrix(int rows, int columns, matrix_t *result) {
  int flag = 0;

  if (rows < 1 || columns < 1) {
    flag = 1;
    result->matrix = NULL;
  }
  // Check ASCII

  if (!flag) {
    result->rows = rows;
    result->columns = columns;
    result->matrix = (double **)calloc(rows, sizeof(double *));

    if (result->matrix) {
      for (int i = 0; i < rows; i++) {
        result->matrix[i] = (double *)calloc(columns, sizeof(double));
        if (!result->matrix[i]) {
          flag = 1;
        }
      }
    } else {
      flag = 1;
    }
  }

  if (flag) {
    s21_remove_matrix(result);
  }

  return flag;
}
