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

    result1 = 1;
    result2 = 1;

    matrix_t result;
    int check = s21_sum_matrix(&matrix1, &matrix2, &result);

    if (!check) {
        _return_matrix(&result);
    }
    
    printf("%d", check);
    return  result1 * result2;
}