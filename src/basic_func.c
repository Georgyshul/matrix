#include "matrix.h"
#include <math.h>


int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {

}

int same_size(matrix_t* A, matrix_t* B) {
    return (A->rows == B->rows && A->columns == B->columns) ? 0 : 2;
}