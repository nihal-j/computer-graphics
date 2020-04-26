CC = g++
CFLAGS = -Wall -I include

target = main

objects = build/main.o build/image.o build/color.o build/vector3.o build/camera.o build/ray.o

$(target): $(objects)
	$(CC) $(CFLAGS) $(objects) -o $(target)

build/%.o: src/%.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm $(target) $(objects)

build/main.o: include/color.hpp include/image.hpp include/vector3.hpp
build/image.o: include/image.hpp include/color.hpp
build/color.o: include/color.hpp
build/vector3.o: include/vector3.hpp
build/ray.o: include/ray.hpp include/vector3.hpp
build/camera.o: include/ray.hpp include/vector3.hpp