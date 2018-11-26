# compiler
CC			= g++
# compile options
CFLAGS	= -std=c++11 -Wall
# header dependencies
DEPS 		= main.cpp Person.hpp Note.hpp Student.hpp 
# object files to be linked
OBJ			= main.o Person.o Note.o Student.o 

# $@, $^ left and right sides of the :
# compile all .c files including the header files to object files
%.o: %.cpp $(DEPS)
		$(CC) $(CFLAGS) -c $<

# link all object files together and name the output file main
main: $(OBJ)
		$(CC) $(CFLAGS) -o $@ $^

# clean up executable and object files
.PHONY: clean

clean:
		rm -f main $(OBJ)
