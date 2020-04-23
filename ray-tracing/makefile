CC = g++
CFLAGS = -g -Wall -I include

main: build/main.o build/image.o build/color.o
	$(CC) $(CFLAGS) build/image.o build/color.o build/main.o -o main

build/main.o: main.cpp
	$(CC) $(CFLAGS) -c main.cpp -o build/main.o

build/image.o: src/image.cpp
	$(CC) $(CFLAGS) -c src/image.cpp -o build/image.o

build/color.o: src/color.cpp
	$(CC) $(CFLAGS) -c src/color.cpp -o build/color.o