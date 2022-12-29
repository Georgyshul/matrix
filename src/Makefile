CC=gcc
CFLAGS=-Wall -Wextra -Werror -g
LDFLAGS=$(shell pkg-config --cflags --libs check)
GCOVFLAGS=-fprofile-arcs -ftest-coverage

# all: s21_math.a test

# s21_math.a: s21_math.o
# 	ar rc libs21_math.a s21_math.o
# 	ranlib libs21_math.a

test_creation: s21_create_matrix.o s21_remove_matrix.o s21_help_func.o test_creation.o
	$(CC) $(CFLAGS) s21_create_matrix.o s21_remove_matrix.o s21_help_func.o test_creation.o -o test_creation

test_creation.o: matrix.h test_creation.c
	$(CC) $(CFLAGS) -c test_creation.c


test_eq: s21_create_matrix.o s21_remove_matrix.o s21_eq_matrix.o s21_help_func.o test_eq.o
	$(CC) $(CFLAGS) s21_create_matrix.o s21_remove_matrix.o s21_eq_matrix.o s21_help_func.o test_eq.o -o test_eq

test_eq.o: matrix.h test_eq.c
	$(CC) $(CFLAGS) -c test_eq.c


test_sum: s21_create_matrix.o s21_remove_matrix.o s21_help_func.o s21_sum_matrix.o test_sum.o 
	$(CC) $(CFLAGS) s21_create_matrix.o s21_remove_matrix.o s21_help_func.o s21_sum_matrix.o test_sum.o -o test_sum

test_sum.o: matrix.h test_sum.c
	$(CC) $(CFLAGS) -c test_sum.c


test_sub: s21_create_matrix.o s21_remove_matrix.o s21_help_func.o s21_sum_matrix.o s21_mult_number.o s21_sub_matrix.o test_sub.o 
	$(CC) $(CFLAGS) s21_create_matrix.o s21_remove_matrix.o s21_help_func.o s21_sum_matrix.o s21_mult_number.o s21_sub_matrix.o test_sub.o -o test_sub

test_sub.o: matrix.h test_sub.c
	$(CC) $(CFLAGS) -c test_sub.c



s21_create_matrix.o: matrix.h s21_create_matrix.c
	$(CC) $(CFLAGS) -c s21_create_matrix.c

s21_remove_matrix.o: matrix.h s21_remove_matrix.c
	$(CC) $(CFLAGS) -c s21_remove_matrix.c

s21_eq_matrix.o: matrix.h s21_eq_matrix.c
	$(CC) $(CFLAGS) -c s21_eq_matrix.c

s21_help_func.o: matrix.h s21_help_func.c
	$(CC) $(CFLAGS) -c s21_help_func.c

s21_mult_number.o: matrix.h s21_mult_number.c
	$(CC) $(CFLAGS) -c s21_mult_number.c

s21_sum_matrix.o: matrix.h s21_sum_matrix.o
	$(CC) $(CFLAGS) -c s21_sum_matrix.c

s21_sub_matrix.o: matrix.h s21_sub_matrix.c
	$(CC) $(CFLAGS) -c s21_sub_matrix.c


# test: s21_math.o
# 	$(CC) $(CFLAGS) $(LDFLAGS) s21_math.o test.c
# 	./a.out


clean:
	rm -f *.o test_creation test_eq

rebuild: clean all