#include "parser.hpp"

int count_spaces(char *s)
{
    int cnt = 0;
    for (int i = 0; i < strlen(s); i++)
        if (s[i] == ' ')
            cnt++;
    return cnt;
}

void Parser::load_obj(char* path)
{
    FILE* file = fopen(path, "r");
    while (1)
    {
        char type[256];
        int res = fscanf(file, "%s", type);
        if (res == EOF)
            break;
        if (strcmp(type, "v") == 0)
        {
            char coordinates[3][256];
            fscanf(file, "%s %s %s", coordinates[0], coordinates[1], coordinates[2]);
            glm::vec3 vertex = {atof(coordinates[0]), atof(coordinates[1]), atof(coordinates[2])};
            vertices.push_back(vertex);
        }
        else if (strcmp(type, "vt") == 0)
        {
            char coordinates[2][256];
            fscanf(file, "%s %s", coordinates[0], coordinates[1]);
            glm::vec2 vertex = {atof(coordinates[0]), atof(coordinates[1])};
            textures.push_back(vertex);
        }
        else if (strcmp(type, "n") == 0)
        {
            char coordinates[3][256];
            fscanf(file, "%s %s %s", coordinates[0], coordinates[1], coordinates[2]);
            glm::vec3 vertex = {atof(coordinates[0]), atof(coordinates[1]), atof(coordinates[2])};
            normals.push_back(vertex);
        }
        else if (strcmp(type, "n") == 0)
        {
            char coordinates[3][256];
            fscanf(file, "%s %s %s", coordinates[0], coordinates[1], coordinates[2]);
            glm::vec3 vertex = {atof(coordinates[0]), atof(coordinates[1]), atof(coordinates[2])};
            normals.push_back(vertex);
        }
        else if (strcmp(type, "f") == 0)
        {
            int vIndex[4], tIndex[4], nIndex[4];
            char line[256];
            fgets(line, sizeof line, file);
            int cnt = count_spaces(line + 1);
            // std::cout << cnt << "\n";
            if (cnt == 3)
                sscanf(line, "%d/%d/%d %d/%d/%d %d/%d/%d %d/%d/%d", &vIndex[0], &tIndex[0], &nIndex[0], &vIndex[1], &tIndex[1], &nIndex[1], &vIndex[2], &tIndex[2], &nIndex[2], &vIndex[3], &tIndex[3], &nIndex[3]);
            else
            {
                sscanf(line, "%d/%d/%d %d/%d/%d %d/%d/%d", &vIndex[0], &tIndex[0], &nIndex[0], &vIndex[1], &tIndex[1], &nIndex[1], &vIndex[2], &tIndex[2], &nIndex[2]);
                vIndex[3] = tIndex[3] = nIndex[3] = -1;
            }

            glm::vec4 v, t, n;
            for (int i = 0; i < 4; i++)
                v[i] = vIndex[i], t[i] = tIndex[i], n[i] = nIndex[i];
            
            faceList.push_back(v);
            textureList.push_back(t);
            normalList.push_back(n);
        }
    }
}

/**
DEBUG 
/

int main()
{
    Parser obj = Parser();
    obj.load_obj("../obj/sofas.obj");

    return 0;
}
// */