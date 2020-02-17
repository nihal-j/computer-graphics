CC = g++
CFLAGS = -Wall
GL_FLAGS = -lglfw3 -lGL -lm -lXrandr -lXi -lX11 -lXxf86vm -lpthread -ldl

main: main.o
	$(CC) build/main.o build/glad.o $(GL_FLAGS) -o main

main.o: main.cpp glad.o
	$(CC) -c -I include main.cpp -o build/main.o
	
glad.o: include/glad/glad.c
	$(CC) -c include/glad/glad.c -o build/glad.o

clean:
	$(RM) main