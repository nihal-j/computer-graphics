CC = g++
CFLAGS = -Wall -I include
GLUT_FLAGS = -lGL -lGLU -lglut

main: build/main.o build/floor.o build/table.o build/chair.o build/dining.o
	$(CC) $(CFLAGS) build/floor.o build/table.o build/chair.o build/dining.o build/main.o $(GLUT_FLAGS) -o main

build/main.o: main.cpp
	$(CC) $(CFLAGS) -c main.cpp -o build/main.o

build/floor.o: src/floor.cpp
	$(CC) $(CFLAGS) -c src/floor.cpp -o build/floor.o

build/table.o: src/table.cpp
	$(CC) $(CFLAGS) -c src/table.cpp -o build/table.o

build/chair.o: src/chair.cpp
	$(CC) $(CFLAGS) -c src/chair.cpp -o build/chair.o

build/dining.o: src/dining.cpp
	$(CC) $(CFLAGS) -c src/dining.cpp -o build/dining.o