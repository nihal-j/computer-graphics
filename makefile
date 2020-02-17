CC = g++
CFLAGS = -Wall
GL_FLAGS = -lglfw3 -lGL -lm -lXrandr -lXi -lX11 -lXxf86vm -lpthread -ldl

main: main.o
	$(CC) build/main.o build/glad.o build/graphics_engine.o build/line.o $(GL_FLAGS) -o main

line: line.o
	$(CC) build/line.o $(GL_FLAGS) -o line

main.o: main.cpp line.o graphics_engine.o glad.o
	$(CC) -c -I include main.cpp -o build/main.o

graphics_engine: graphics_engine.o
	$(CC) build/graphics_engine.o build/glad.o $(GL_FLAGS) -o graphics_engine

graphics_engine.o: src/graphics_engine.cpp glad.o
	$(CC) -c -I include src/graphics_engine.cpp -o build/graphics_engine.o

line.o: src/line.cpp
	$(CC) -c -I include src/line.cpp -o build/line.o
	
glad.o: include/glad/glad.c
	$(CC) -c include/glad/glad.c -o build/glad.o

clean:
	$(RM) main