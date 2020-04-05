#ifndef OBJ_HPP
#define OBJ_HPP

#include <vector>
#include <glm/glm.hpp>
#include <GL/glut.h>
#include "parser.hpp"

class Object
{
    private:
        std::vector<glm::vec3> vertexCoordinates;
        std::vector<glm::vec4> faces;
        char path[256];

    public:
        Object(char* path);
        void draw();
        void load();
};

#endif