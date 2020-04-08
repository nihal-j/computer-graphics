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
        /**
         * @brief Loads the .obj file into the member variables as their names suggests
         * 
         * @param path path to .obj file
         */
        void load_obj(char* path);
        /**
         * @brief Get the vertices object
         * 
         * @return std::vector<glm::vec3> 
         */
        std::vector<glm::vec3> get_vertices()   { return vertices; };
        /**
         * @brief Get the faces object
         * 
         * @return std::vector<glm::vec4> 
         */
        std::vector<glm::vec4> get_faces()      { return faceList; };

};

#endif