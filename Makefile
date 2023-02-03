run: compile
	./main

compile: main.o fonctions.o
	gcc -Wall -o main main.o fonctions.o -g

main.o: main.c fonctions.o
	gcc -Wall -c main.c fonctions.h fonctions.c -g

fonctions.o: fonctions.h fonctions.c
	gcc -Wall -c fonctions.h fonctions.c -g

clean: 
	rm *.o
	rm *.gch

valgrind: compile
	valgrind ./main
