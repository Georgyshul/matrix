#include "s21_matrix.h"

int s21_transpose(matrix_t *A, matrix_t *result) {
    int creation_flag = 2;

    if (A->columns == A->rows) {
        creation_flag = s21_create_matrix(A->rows, A->columns, result);
    }

    if (!creation_flag) {
        for (int i = 0; i < A->rows; i++) {
            for (int j = 0; j < A->columns; j++) {
                result->matrix[i][j] = A->matrix[j][i];
            }
        }
    }

    return creation_flag;
}