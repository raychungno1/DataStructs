# Ray Chung

all: intTest

# Test linked list w/ ints
intTest: intTest.o dll.o
	gcc -g -o $@ $^ 

# Turn c files into o files
%.o:%.c *.h
	gcc -ansi -pedantic -Wimplicit-function-declaration -Wreturn-type -g -c $< -o $@

# Detects any non-freed malloc calls
memLeak:
	valgrind --tool=memcheck intTest

# Clean
clean:
	rm -rf *.o intTest
