CC = g++
CFLAGS = -g -Wall -I include

main: build/main.o build/image.o build/color.o build/vector3.o
	$(CC) $(CFLAGS) build/image.o build/color.o build/vector3.o build/main.o -o main

build/main.o: main.cpp
	$(CC) $(CFLAGS) -c main.cpp -o build/main.o

test: build/test.o build/image.o build/color.o build/vector3.o
	$(CC) $(CFLAGS) build/image.o build/color.o build/vector3.o build/test.o -o test

build/test.o: test.cpp
	$(CC) $(CFLAGS) -c test.cpp -o build/test.o

build/image.o: src/image.cpp
	$(CC) $(CFLAGS) -c src/image.cpp -o build/image.o

build/color.o: src/color.cpp
	$(CC) $(CFLAGS) -c src/color.cpp -o build/color.o

build/vector3.o: src/vector3.cpp
	$(CC) $(CFLAGS) -c src/vector3.cpp -o build/vector3.o