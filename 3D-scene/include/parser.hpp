#ifndef PARSER_HPP
#define PARSER_HPP

#include <fstream>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
#include <GL/glut.h>
#include <glm/glm.hpp>

class Parser
{
    private:
        std::vector<glm::vec3> vertices, normals;
        std::vector<glm::vec2> textures;
        std::vector<glm::vec4> faceList, normalList, textureList;

    public:
        void load_obj(char* path);
        std::vector<glm::vec3> get_vertices()   { return vertices; };
        std::vector<glm::vec4> get_faces()      { return faceList; };

};

#endif