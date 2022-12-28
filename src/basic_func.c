#include "matrix.h"
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

int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
    int flag = same_size(A, B);
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

int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
    matrix_t T;
    int mult_flag = s21_mult_number(B, -1.0, &T);
    int sum_flag = 2;

    if (!mult_flag) {
        sum_flag = s21_sum_matrix(A, &T, result);
    }
    return sum_flag;
}

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

int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {

}

int same_size(matrix_t* A, matrix_t* B) {
    return (A->rows == B->rows && A->columns == B->columns) ? 0 : 2;
}