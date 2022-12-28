#include <stdio.h>
#include "matrix.h"

int main() {
    int n, m = 0;
    int result = 1;
    int scanf_check = scanf("%d %d", &n, &m);

    if (scanf_check == 2) {
        matrix_t matrix;
        result = s21_create_matrix(n, m, &matrix);
        int fill_check = _fill_matrix(&matrix);

        if (!fill_check) {
            _return_matrix(&matrix);
        }

        s21_remove_matrix(&matrix);
    }
    return result;
}