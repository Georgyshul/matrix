#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"

int _fill_matrix(matrix_t* A) {
    int flag = 0;
    for (int i = 0; i < A->rows && !flag; i++) {
        for (int j = 0; j < A->columns && !flag; j++) {
            double value;
            int check = scanf("%lf", &value);

            if (check) {
                A->matrix[i][j] = value;
            } else {
                flag = 1;
            }
        }
    }

    if (flag) {s21_remove_matrix(A);}

    return flag;
}

void _return_matrix(matrix_t* matrix) {
    for (int i = 0; i < matrix->rows; i++) {
        for (int j = 0; j < matrix->columns; j++) {
            printf("%lf", matrix->matrix[i][j]);
            if (j < matrix->columns - 1) {
                printf(" ");
            }
        }
        printf("\n");
    }
}

int _check_calloc_1(int *flag, double** matrix) {
    int check = 1;
    if (matrix == NULL) {
        *flag = 1;
        check = 0;
    }
    return check;
}

int _check_calloc_2(int *flag, double* matrix) {
    int check = 1;
    if (matrix == NULL) {
        *flag = 1;
        check = 0;
    }
    return check;
}