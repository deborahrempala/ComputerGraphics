CC = gcc -Wall -ansi

# Unix Version
#LDARGS 		= -lGL -lGLU -lm -lSDL2_image 

# Windows version
LDARGS 	= -lopengl32 -lglu32 -lm -lSDL2_image 

all:
	$(CC)  shapedraw.c -o shapedraw -ggdb $(LDARGS) $(shell sdl2-config --libs --cflags) 

