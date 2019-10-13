# compiler
CC			= g++
# compile options
CFLAGS	= -std=c++14 -Wall
# header dependencies
DEPS 		= vereine_main.cpp vereine.cpp vereine.hpp 
# object files to be linked
OBJ			= vereine_main.o vereine.o

# $@, $^ left and right sides of the :
# compile all .c files including the header files to object files
%.o: %.cpp $(DEPS)
		$(CC) $(CFLAGS) -c $<

# link all object files together and name the output file main
vereine_main: $(OBJ)
		$(CC) $(CFLAGS) -o $@ $^

# clean up executable and object files
.PHONY: clean

clean:
		rm -f vereine_main $(OBJ)
