SRCPATH := src/
# release path 
RLSPATH := release/

OBJ := $(RLSPATH)main.o

run: main.exe
	./$^

main.exe : $(RLSPATH)main.o
	g++ $? -o $@

clean:
	rm *.exe *.o


#####################
# IMPLICIT RULES
#####################

$(RLSPATH)%.o : $(SRCPATH)%.cpp
	g++ -c $^ -o $@