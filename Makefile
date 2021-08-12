run: main.exe
	./$^

main.exe : main.o
	g++ $? -o $@

#####################
# IMPLICIT RULES
#####################
%.o : %.cpp
	g++ -c $^