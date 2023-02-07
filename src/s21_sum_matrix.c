#include "s21_matrix.h"

int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
    int flag = _same_size(A, B);
    int creation_flag = 1;

    if (!flag) {
        creation_flag = s21_create_matrix(A->rows, A->columns, result);
    }

    if (!creation_flag) {
        for (int i = 0; i < A->rows; i++) {
            for (int j = 0; j < A->columns; j++) {
                result->matrix[i][j] = A->matrix[i][j] + B->matrix[i][j];
            }
        }
    }
    return !creation_flag ? 0 : 2;   
}