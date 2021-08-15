###################
# MACROS
###################

# src path
SRCPATH :=src/
# release path 
RLSPATH :=release/
# include path
INCPATH :=include/

# object files 
OBJ  	:=$(RLSPATH)utl.o $(RLSPATH)main.o 
# header dependencies
DEPS 	:=$(INCPATH)utl.hpp

# target
TARGET 	:=$(RLSPATH)main.exe

# compiler flags
CFLAGS 	:=-iquote. -Wall

#####################
# EXPLICIT RULES
#####################

all : run


run: $(TARGET)
	$(TARGET) -g 100000

$(TARGET) : $(OBJ)
	g++ $^ -o $(TARGET) $(CFLAGS)

clean:
	rm $(RLSPATH)*.exe $(RLSPATH)*.o


#####################
# IMPLICIT RULES
#####################

$(RLSPATH)%.o : $(SRCPATH)%.cpp $(DEPS)
	g++ -c $< -o $@ $(CFLAGS)