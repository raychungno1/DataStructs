# Ray Chung

# Change the last dependency for each new lab
all: intTest

# Test linked list w/ ints
intTest: intTest.o sll.o
	gcc -g -o $@ $^ 

# this entry takes care of C files depending on header files
# It has the flags for compiling the c code
# It you don't like makefiles, consider typing the following line a few
# thousand times this semester and reconsider.
# Be sure that this one doesn't get an inserted line break anywhere
%.o:%.c *.h
	gcc -ansi -pedantic -Wimplicit-function-declaration -Wreturn-type -g -c $< -o $@

# Detects any non-freed malloc calls
memLeak:
	valgrind --tool=memcheck intTest

# Clean
clean:
	rm -rf *.o intTest
