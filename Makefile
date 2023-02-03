run: compile
	./main

compile: main.o fonctions.o AI.o
	gcc -Wall -o main main.o fonctions.o AI.o -g

main.o: main.c fonctions.o AI.o
	gcc -Wall -c main.c fonctions.h fonctions.c AI.h AI.c -g

fonctions.o: fonctions.h fonctions.c
	gcc -Wall -c fonctions.h fonctions.c -g

AI.o: fonctions.o AI.h AI.c
	gcc -Wall -c AI.h AI.c fonctions.h fonctions.c -g

clean: 
	rm *.o
	rm *.gch

valgrind: compile
	valgrind ./main
