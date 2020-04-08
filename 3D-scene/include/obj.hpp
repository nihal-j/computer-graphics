#ifndef OBJ_HPP
#define OBJ_HPP

#include <vector>
#include <glm/glm.hpp>
#include <GL/glut.h>
#include "parser.hpp"

class Object
{
    private:
        /// list of vertex coordinates
        std::vector<glm::vec3> vertexCoordinates;
        /// list of face specifications. If face is a triangle, 4th element is -1
        std::vector<glm::vec4> faces;
        /// path to .obj file
        char path[256];

    public:
        /**
         * @brief Construct a new Object object
         * 
         * @param path path to .obj file
         */
        Object(char* path);
        /**
         * @brief Draw the loaded object
         */
        void draw();
        /**
         * @brief Load an object from .obj file by using `Parser`
         */
        void load();
};

#endif