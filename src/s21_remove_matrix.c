#include "matrix.h"
#include <stdlib.h>

void s21_remove_matrix(matrix_t *A) {
    if (A->matrix) {
        for (int i = 0; i < A->rows; i++) {
            if (A->matrix[i]) {
                free(A->matrix[i]);
            }
        }
        free(A->matrix);
        A->matrix = NULL;
    }
    A->rows = 0;
    A->columns = 0;
}