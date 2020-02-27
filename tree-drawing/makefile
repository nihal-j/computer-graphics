CC = g++
CFLAGS = -Wall
GL_FLAGS = -lglfw3 -lGL -lm -lXrandr -lXi -lX11 -lXxf86vm -lpthread -ldl

main: main.o
	$(CC) -g build/main.o build/glad.o build/graphics_engine.o build/line.o build/circle.o build/tree.o build/generator.o $(GL_FLAGS) -o main

line: line.o
	$(CC) build/line.o $(GL_FLAGS) -o line

circle: circle.o
	$(CC) build/circle.o $(GL_FLAGS) -o circle

tree: tree.o line.o circle.o
	$(CC) build/tree.o build/line.o build/circle.o $(GL_FLAGS) -o tree

generator: generator.o
	$(CC) build/generator.o $(GL_FLAGS) -o generator

graphics_engine: graphics_engine.o line.o circle.o
	$(CC) build/graphics_engine.o build/glad.o build/line.o build/circle.o $(GL_FLAGS) -o graphics_engine

main.o: main.cpp line.o circle.o graphics_engine.o glad.o tree.o generator.o
	$(CC) -g -c -I include main.cpp -o build/main.o

graphics_engine.o: src/graphics_engine.cpp glad.o
	$(CC) -c -I include src/graphics_engine.cpp -o build/graphics_engine.o

line.o: src/line.cpp
	$(CC) -c -I include src/line.cpp -o build/line.o

circle.o: src/circle.cpp
	$(CC) -c -I include src/circle.cpp -o build/circle.o

tree.o: src/tree.cpp
	$(CC) -g -c -I include src/tree.cpp -o build/tree.o

generator.o: src/generator.cpp
	$(CC) -g -c -I include src/generator.cpp -o build/generator.o
	
glad.o: include/glad/glad.c
	$(CC) -c include/glad/glad.c -o build/glad.o

clean:
	$(RM) main