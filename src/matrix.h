#ifndef SRC_MATRIX_H_
#define SRC_MATRIX_H_

#define SUCCESS 1
#define FAILURE 0
#define EPS 1e-7

typedef struct matrix_struct {
    double** matrix;
    int rows;
    int columns;
} matrix_t;

int s21_create_matrix(int rows, int columns, matrix_t *result);  // ok
void s21_remove_matrix(matrix_t *A);  // ok

int s21_eq_matrix(matrix_t *A, matrix_t *B);  // ok
int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result);
int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result);

int s21_mult_number(matrix_t *A, double number, matrix_t *result);
int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result);


int _fill_matrix(matrix_t* A);
void _return_matrix(matrix_t* matrix);
int _check_calloc_1(int *flag, double** matrix);
int _check_calloc_2(int *flag, double* matrix);
int same_size(matrix_t* A, matrix_t* B);

#endif  // SRC_MATRIX_H_