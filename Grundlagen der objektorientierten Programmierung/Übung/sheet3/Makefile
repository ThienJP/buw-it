# compiler
CC			= g++
# compile options
CFLAGS	= -std=c++11 -Wall
# header dependencies
DEPS 		= binomi.h faculty.h
# object files to be linked
OBJ			= binomial.o faku.o nueberk.o 

# $@, $^ left and right sides of the :
# compile all .c files including the header files to object files
%.o: %.c $(DEPS)
		$(CC) $(CFLAGS) -c -o $@

# link all object files together and name the output file main_make
binomial: $(OBJ)
		$(CC) $(CFLAGS) -o $@ $^

# clean up executable and object files
.PHONY: clean

clean:
		rm -f binomial $(OBJ)
