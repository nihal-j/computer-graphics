CC = g++
CFLAGS = -Wall -I include -g

target = main

objects = build/main.o build/image.o build/color.o build/vector3.o build/camera.o build/ray.o build/object_base.o build/sphere.o build/scene.o build/light_base.o build/light_point.o build/plane.o

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
build/object_base.o: include/object_base.hpp include/vector3.hpp include/ray.hpp include/color.hpp
build/sphere.o: include/object_base.hpp include/vector3.hpp include/sphere.hpp include/ray.hpp include/color.hpp
build/scene.o: include/object_base.hpp include/vector3.hpp include/ray.hpp include/color.hpp include/scene.hpp
build/light_base.o: include/light_base.hpp include/ray.hpp include/vector3.hpp include/color.hpp
build/light_point.o: include/light_base.hpp include/ray.hpp include/vector3.hpp include/color.hpp include/light_point.hpp
build/plane.o: include/plane.hpp include/vector3.hpp include/sphere.hpp include/ray.hpp include/color.hpp