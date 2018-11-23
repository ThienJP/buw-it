# compiler
CC			= g++
# compile options
CFLAGS	= -std=c++11 -Wall
# header dependencies
DEPS 		= flug.hpp
# object files to be linked
OBJ			= flug.o

# $@, $^ left and right sides of the :
# compile all .c files including the header files to object files
%.o: %.c $(DEPS)
		$(CC) $(CFLAGS) -c $<

# link all object files together and name the output file main_make
flug: $(OBJ)
		$(CC) $(CFLAGS) -o $@ $^

# clean up executable and object files
.PHONY: clean

clean:
		rm -f flug $(OBJ)
