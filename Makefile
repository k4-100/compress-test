##################
# VARIABLES
##################

SRCPATH := src/
# release path 
RLSPATH := release/

OBJ := $(RLSPATH)main.o


###############
# EXPLICIT RULES
###############


run: main.exe
	$(RLSPATH)$^

main.exe : $(OBJ)
	g++ $? -o $(RLSPATH)$@

clean:
	rm $(RLSPATH)*.exe $(RLSPATH)*.o


#####################
# IMPLICIT RULES
#####################

$(RLSPATH)%.o : $(SRCPATH)%.cpp
	g++ -c $^ -o $@