#include "obj.hpp"

Object::Object(char* path)
{
    strcpy(this -> path, path);
}

void Object::draw()
{
    glEnableClientState(GL_VERTEX_ARRAY);
    int size = vertexCoordinates.size()*3;
    float vertices[size + 1];

    // unpacking vertexCoordinates into vertices
    int k = 0;
    for (int i = 0; i < vertexCoordinates.size(); i++)
        for (int j = 0; j < 3; j++)
            vertices[k++] = vertexCoordinates[i][j];
    
    // loading vertices into memory
    glVertexPointer(3, GL_FLOAT, 0, vertices);

    glColor3f(0.878, 0.619, 0.741);     // orange
    for (int i = 0 ; i < faces.size(); i++)
    {
        if (faces[i][3] == -1)
        {
            // a triangle is to be drawn
            int indices[3];
            for (int j = 0; j < 3; j++)
                indices[j] = faces[i][j] - 1;

            glPushMatrix();
            {
                glScalef(3, 3, 3);
                glDrawElements(GL_POLYGON, 3, GL_UNSIGNED_INT, indices);
            }
            glPopMatrix();
        }
        else
        {
            // a quad is to be drawn
            int indices[4];
            for (int j = 0; j < 4; j++)
                indices[j] = faces[i][j] - 1;
            glPushMatrix();
            {
                glScalef(3, 3, 3);
                glDrawElements(GL_POLYGON, 4, GL_UNSIGNED_INT, indices);
            }
            glPopMatrix();
        }
    }
}

void Object::load()
{
    Parser* parser = new Parser;
    parser -> load_obj("obj/sofas.obj");
    vertexCoordinates = parser -> get_vertices();
    faces = parser -> get_faces();
    free(parser);
}