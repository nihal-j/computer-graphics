CC = g++
CFLAGS = -Wall
GL_FLAGS = -lglfw3 -lGL -lm -lXrandr -lXi -lX11 -lXxf86vm -lpthread -ldl

triangle: triangle.o
	$(CC) build/triangle.o build/glad.o $(GL_FLAGS) -o triangle

triangle.o: triangle.cpp
	$(CC) -c triangle.cpp -o build/triangle.o

line: line.o
	$(CC) build/line.o build/glad.o $(GL_FLAGS) -o line

line.o: line.cpp
	$(CC) -c line.cpp -o build/line.o

glad.o: include/glad/glad.c
	$(CC) -c include/glad/glad.c -o build/glad.o

clean:
	$(RM) triangle