prog: titelseite.o farben.o gruppen_intern.o gruppen.o auslosung_intern.o auslosung_random.o  auslosung_punkte.o auslosung.o wetten.o main.o
	gcc -o prog titelseite.o farben.o gruppen_intern.o gruppen.o auslosung_intern.o auslosung_random.o auslosung_punkte.o auslosung.o wetten.o main.o

farben.o: ./Farben/farben.c
	gcc -c ./Farben/farben.c -ansi -pedantic -Wall -Wextra

titelseite.o: ./Titelseite/titelseite.c
	gcc -c ./Titelseite/titelseite.c -ansi -pedantic -Wall -Wextra

gruppen.o: ./Gruppenphase/gruppen.c
	gcc -c ./Gruppenphase/gruppen.c -ansi -pedantic -Wall -Wextra

gruppen_intern.o: ./Gruppenphase/gruppen_intern.c
	gcc -c ./Gruppenphase/gruppen_intern.c -ansi -pedantic -Wall -Wextra

auslosung_intern.o: ./Auslosung/auslosung_intern.c
	gcc -c ./Auslosung/auslosung_intern.c -ansi -pedantic -Wall -Wextra

auslosung_random.o: ./Auslosung/auslosung_random.c
	gcc -c ./Auslosung/auslosung_random.c -ansi -pedantic -Wall -Wextra

auslosung_punkte.o: ./Auslosung/auslosung_punkte.c
	gcc -c ./Auslosung/auslosung_punkte.c -ansi -pedantic -Wall -Wextra

auslosung.o: ./Auslosung/auslosung.c
	gcc -c ./Auslosung/auslosung.c -ansi -pedantic -Wall -Wextra

wetten.o: ./Wetten/wetten.c
	gcc -c ./Wetten/wetten.c -ansi -pedantic -Wall -Wextra

main.o: main.c
	gcc -c main.c -ansi -pedantic -Wall -Wextra

clean:
	rm -f *.o
