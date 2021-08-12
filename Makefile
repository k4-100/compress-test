run: main.exe
	./$^

main.exe : main.o
	g++ $? -o $@

clean:
	rm *.exe *.o


#####################
# IMPLICIT RULES
#####################
%.o : %.cpp
	g++ -c $^