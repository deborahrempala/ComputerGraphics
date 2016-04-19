

CFLAGS =  $(shell sdl2-config --cflags)  -O2 
LIBS = -lSDL2_image -lSDL2_mixer $(shell sdl2-config --libs) -lm


main:	new2.cpp Fixed_print.c
	gcc $(CFLAGS) -c Fixed_print.c
	g++ $(CFLAGS) new2.cpp Fixed_print.o -o game $(LIBS)




