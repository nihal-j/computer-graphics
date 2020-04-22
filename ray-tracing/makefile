CC = g++
CFLAGS = -g -Wall -I include

main: build/main.o build/image.o 
	$(CC) $(CFLAGS) build/image.o  build/main.o -o main

build/main.o: main.cpp
	$(CC) $(CFLAGS) -c main.cpp -o build/main.o

build/image.o: src/image.cpp
	$(CC) $(CFLAGS) -c src/image.cpp -o build/image.o