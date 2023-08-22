CC=g++
SOURCES=s21_matrix_oop.cc #s21_matrix_oop.h
CPPFLAGS=-Wall -Wextra -Werror -std=c++17
LDFLAGS=-lgtest -lgtest_main -lpthread
GCOV_FLAGS=
TEST_SOURCES=test.cc

all: s21_matrix_oop.a

s21_matrix_oop.a:
	$(CC) -c $(SOURCES)
	ar rc s21_matrix_oop.a *.o
	ranlib s21_matrix_oop.a

test:
	$(CC) $(SOURCES) $(TEST_SOURCES) $(LDFLAGS) $(GCOV_FLAGS) -o test
	./test

gcov_report: GCOV_FLAGS += -fprofile-arcs -ftest-coverage
gcov_report: clean test
	./test > /dev/null
	lcov --no-external -o report.info -c -d .
	genhtml -o "html_report" report.info
	open html_report/index.html

style:
	clang-format --style=google -i s21_matrix_oop.cc s21_matrix_oop.h test.cc
	clang-format --style=google -n s21_matrix_oop.cc s21_matrix_oop.h test.cc

clean:
	rm -rf *.o *.gch *.a *.out test *.gcno *.gcda *.info html_report

.PHONY: all s21_matrix_oop test style clean gcov_report