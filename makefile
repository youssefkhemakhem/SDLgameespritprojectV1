game:main.o head.o
	gcc main.c head.c -o game -g -lSDL -lSDL_image -lSDL_ttf -lSDL_mixer
main.o:main.c
	gcc -c main.c
head.o:head.c
	gcc -c head.c
