CC = g++
CFLAGS = -Wall -I include
GLUT_FLAGS = -lGL -lGLU -lglut

main: main.o
	$(CC) $(CFLAGS) build/main.o $(GLUT_FLAGS) -o main

main.o: main.cpp
	$(CC) $(CFLAGS) -c main.cpp -o build/main.o