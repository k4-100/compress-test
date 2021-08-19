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
DEPS 	:=$(INCPATH)utl.h

# target
TARGET 	:=$(RLSPATH)main.exe

# compiler flags
CFLAGS 	:=-iquote. -Wall

# number big enough to cause compression/decompression to run for few seconds
MIL = 1000000


#####################
# EXPLICIT RULES
#####################

all : run


run: $(TARGET)
	$(TARGET) 
$(TARGET) : $(OBJ)
	gcc $^ -o $(TARGET) $(CFLAGS)

clean:
	rm $(RLSPATH)*.exe $(RLSPATH)*.o


#####################
# IMPLICIT RULES
#####################

$(RLSPATH)%.o : $(SRCPATH)%.c $(DEPS)
	gcc -c $< -o $@ $(CFLAGS)