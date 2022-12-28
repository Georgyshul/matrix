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



s21_create_matrix.o: matrix.h s21_create_matrix.c
	$(CC) $(CFLAGS) -c s21_create_matrix.c

s21_remove_matrix.o: matrix.h s21_remove_matrix.c
	$(CC) $(CFLAGS) -c s21_remove_matrix.c

s21_eq_matrix.o: matrix.h s21_eq_matrix.c
	$(CC) $(CFLAGS) -c s21_eq_matrix.c

s21_help_func.o: matrix.h s21_help_func.c
	$(CC) $(CFLAGS) -c s21_help_func.c




test_basic: s21_create_matrix.o basic_func.o test_basic.o
	$(CC) $(CFLAGS) s21_create_matrix.o basic_func.o test_basic.o -o test_basic

basic_func.o: matrix.h basic/basic_func.h basic/basic_func.c
	$(CC) $(CFLAGS) -c basic/basic_func.c

test_basic.o: matrix.h creation/creation.h basic/basic_func.h basic/test_basic.c
	$(CC) -c basic/test_basic.c



# test: s21_math.o
# 	$(CC) $(CFLAGS) $(LDFLAGS) s21_math.o test.c
# 	./a.out


clean:
	rm -f *.o test_creation test_eq

rebuild: clean all