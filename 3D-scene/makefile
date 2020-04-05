CC = g++
CFLAGS = -g -Wall -I include
GLUT_FLAGS = -lGL -lGLU -lglut

main: build/main.o build/floor.o build/table.o build/chair.o build/dining.o build/wall.o build/tv.o build/parser.o build/obj.o
	$(CC) $(CFLAGS) build/floor.o build/table.o build/chair.o build/dining.o build/wall.o build/tv.o build/parser.o build/obj.o build/main.o $(GLUT_FLAGS) -o main

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

build/wall.o: src/wall.cpp
	$(CC) $(CFLAGS) -c src/wall.cpp -o build/wall.o

build/tv.o: src/tv.cpp
	$(CC) $(CFLAGS) -c src/tv.cpp -o build/tv.o

build/parser.o: src/parser.cpp
	$(CC) $(CFLAGS) -c src/parser.cpp -o build/parser.o

build/obj.o: src/obj.cpp
	$(CC) $(CFLAGS) -c src/obj.cpp -o build/obj.o