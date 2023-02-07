#include <stdio.h>
#include <stdlib.h>
#include "s21_matrix.h"

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

int _same_size(matrix_t* A, matrix_t* B) {
    return (A->rows == B->rows && A->columns == B->columns) ? 0 : 2;
}

// double _det(matrix_t* A) {
//     double d = 0;
//     if (A->rows == 1) {
//         return A->matrix[0][0];
//     } else if (A->rows > 1) {
//         int sign = 1;
//         for (int i = 0; i < A->columns; i++) {
//             matrix_t* tmp;
//             s21_create_matrix(A->rows - 1, A->rows - 1, tmp);
//             _copy_matrix(tmp, A, A->rows - 1, i);
//             d += sign * A->matrix[0][i] * _det(tmp);
//             sign *= -1;
//             s21_remove_matrix(tmp);
//         }
//     }
//     return d;
// }

void _copy_matrix(matrix_t *new, matrix_t* old, int size, int column) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (j >= column) {
                new->matrix[i][j] = old->matrix[i+1][j+1];
            } else {
                new->matrix[i][j] = old->matrix[i+1][j];
            }
        }
    }
}