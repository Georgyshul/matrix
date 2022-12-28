#include <stdio.h>
#include "matrix.h"

int main() {
    int n1, m1;
    scanf("%d %d", &n1, &m1);
    matrix_t matrix1;
    int result1 = s21_create_matrix(n1, m1, &matrix1);
    _fill_matrix(&matrix1);

    int n2, m2;
    scanf("%d %d", &n2, &m2);
    matrix_t matrix2;
    int result2 = s21_create_matrix(n2, m2, &matrix2);
    _fill_matrix(&matrix2);

    int result = s21_eq_matrix(&matrix1, &matrix2);
    result1 = 1;
    result2 = 1;
    // _return_matrix(&matrix);
    // s21_remove_matrix(&matrix);
    printf("%d", result);
    return result * result1 * result2;
}