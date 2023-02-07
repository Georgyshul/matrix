#include "s21_matrix.h"

int s21_mult_number(matrix_t *A, double number, matrix_t *result) {
    int creation_flag = s21_create_matrix(A->rows, A->columns, result);

    if (!creation_flag) {
        for (int i = 0; i < A->rows; i++) {
            for (int j = 0; j < A->columns; j++) {
                result->matrix[i][j] = A->matrix[i][j] * number;
            }
        }
    }
    return !creation_flag ? 0 : 2;
}