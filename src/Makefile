CC=gcc
SRC_DIR = .
TEST_DIR = tests

SRC := $(shell find ${SRC_DIR} -name "s21_*.c" | sed -e 's/\.\///')

BUILD_DIR = obj
BUILD_TEST_DIR = obj_tests

OBJS := $(SRC:%.c=${BUILD_DIR}/%.o)

CFLAGS=-Wall -Wextra -Werror -g
LDFLAGS=$(shell pkg-config --cflags --libs check)
INC_CHECK ?= $(shell pkg-config --cflags check)
GCOVFLAGS=-fprofile-arcs -ftest-coverage



all: s21_matrix.a test

s21_matrix.a: $(OBJS)
	@mkdir -p ${BUILD_DIR}
	ar rc s21_matrix.a $(OBJS)
	ranlib s21_matrix.a


${BUILD_DIR}/%.o: %.c
	@mkdir -p $(dir $@)
	${CC} ${CFLAGS} -c $< -o $@

${BUILD_TEST_DIR}/test.o: ${TEST_DIR}/test.c
	@mkdir -p $(BUILD_TEST_DIR)
	$(CC) $(INC_CHECK) -c -o $(BUILD_TEST_DIR)/test.o ${TEST_DIR}/test.c


test: s21_matrix.a ${BUILD_TEST_DIR}/test.o
	$(CC) $(CFLAGS) ${BUILD_TEST_DIR}/test.o s21_matrix.a $(LDFLAGS) -o test.out
	./test.out



clean:
	rm -r ${BUILD_DIR}
	rm -f s21_matrix.a
	rm -r ${BUILD_TEST_DIR}
	rm test.out

rebuild: clean all