CC = gcc
OBJ = trim.o
TRIM_TEST_OBJ = string_trim.o

build: $(OBJ)
	$(CC) -o libtrim.so $(OBJ) -shared -fPIC

$(OBJ):
	$(CC) -c -O3 -fPIC -MMD -MP -MF $(OBJ).d -o $(OBJ) trim.c

$(TRIM_TEST_OBJ):
	$(CC) -c -O3 -fPIC -MMD -MP -MF tests/$(TRIM_TEST_OBJ).d -o tests/$(TRIM_TEST_OBJ) tests/string_trim.c

test: build $(TRIM_TEST_OBJ)
	$(CC) -o libtrim_test $(OBJ) tests/$(TRIM_TEST_OBJ) -lcunit
	./libtrim_test

clean:
	rm -f *.o *.o.d *.so tests/*.o tests/*.o.d libtrim_test
