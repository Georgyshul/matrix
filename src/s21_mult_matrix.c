#include "s21_matrix.h"

int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
    int creation_flag = 2;

    if (A->columns == B->rows) {
        creation_flag = s21_create_matrix(A->rows, B->columns, result);
    }

    if (!creation_flag) {
        for (int i = 0; i < A->rows; i++) {
            for (int j = 0; j < B->columns; j++) {
                result->matrix[i][j] = 0;
                for (int r = 0; r < A->columns; r++) {
                    result->matrix[i][j] += A->matrix[i][r] * B->matrix[r][j];
                }
            }
        }
    }

    return creation_flag;
}