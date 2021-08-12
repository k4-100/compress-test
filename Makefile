###################
# VARIABLES
###################

# src path
SRCPATH :=src/
# release path 
RLSPATH :=release/
# include path
INCPATH :=include/

# object files 
OBJ  	:=$(RLSPATH)main.o $(RLSPATH)utl.o
# header dependencies
DEPS 	:=$(INCPATH)utl.hpp

# compiler flags
CFLAGS 	:=-iquote. -Wall

#####################
# EXPLICIT RULES
#####################


run: main.exe
	$(RLSPATH)$^

main.exe : $(OBJ)
	g++ $? -o $(RLSPATH)$@

clean:
	rm $(RLSPATH)*.exe $(RLSPATH)*.o


#####################
# IMPLICIT RULES
#####################

$(RLSPATH)%.o : $(SRCPATH)%.cpp $(DEPS)
	g++ -c $< -o $@ $(CFLAGS)