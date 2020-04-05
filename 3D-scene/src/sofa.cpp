#include "sofa.hpp"

std::vector<glm::vec3> vertexCoordinates;
std::vector<glm::vec4> faces;

void draw_sofa()
{
    draw_obj(vertexCoordinates, faces);
}

void load_sofa()
{
    Parser parser = Parser();
    parser.load_obj("obj/sofas.obj");
    vertexCoordinates = parser.get_vertices();
    faces = parser.get_faces();
}