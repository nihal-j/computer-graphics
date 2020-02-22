#ifndef GRAPHICS_ENGINE_H
#define GRAPHICS_ENGINE_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <vector>
#include "circle.h"
#include "line.h"
#include "screen.h"

class GraphicsEngine
{
    private:

        ///
        unsigned int shaderProgram;
        ///
        unsigned int vao;
        ///
        GLFWwindow* window;
        /// primitives
        int primitives[1000][2000];
        int pointCount[1000];
        /// primitive count
        int pCount;

        /**
         * @brief Initializes GLFW to make it ready for rendering and processing
         * I/O.
         * 
         * Several activities are performed:
         *  - GLFW is configured to be set to CORE profile.
         *  - `window` is initialized.
         *  - callback functions are registered to the window.
         *  - GLAD is initialized.
         *  - viewport is initialized.
         *  - vertex and fragment shaders are compiled as single shader program.
         * 
         * @return GLFWwindow* pointer to the current window.
         */
        GLFWwindow* initialize();

        /// 
        const char *vertexShaderSource = 
            "#version 330 core\n"
            "layout (location = 0) in vec3 aPos;\n"
            "out vec4 color;\n"
            "void main()\n"
            "{\n"
            "   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0f);\n"
            "   color.x = aPos.x;\n"
            "   color.y = aPos.y;\n"
            "}\n\0";
        
        ///
        const char *fragmentShaderSource = 
            "#version 330 core\n"
            "out vec4 fragColor;\n"
            "in vec4 color;\n"
            "void main()\n"
            "{\n"
            "   fragColor = vec4(0.25f, 0.75f, 0.5f, 1.0f);\n"
            "}\n\0";
        
        const char *creativeFragmentShaderSource = 
            "#version 330 core\n"
            "out vec4 fragColor;\n"
            "in vec4 color;\n"
            "void main()\n"
            "{\n"
            "   float xColor = (color.x + 1.0) / 2.0;\n"
            "   float yColor = (color.y + 1.0) / 2.0;\n"
            "   fragColor = vec4(yColor*yColor, xColor*xColor, 0.75f, 1.0f);\n"
            "}\n\0";

        /**
         * @brief 
         * 
         * @param x 
         * @param y 
         * @param z 
         */
        void add_primitive(int* points, int pointCount);
        void plot_points(const int* points, int pointCount);
        void normalize(float &x, float &y, float &z);
        

    public:

        /**
         * @brief Construct a new Graphics object.
         * 
         */
        GraphicsEngine();

        /**
         * @brief A callback function to process any I/O done by user
         * to the current window.
         * 
         * @param window pointer to the current window.
         */
        void process_input();

        /**
         * @brief 
         * 
         * @param points 
         * @param pointCount 
         */
        void load_line(Line line);
        void load_circle(Circle circle);
        void draw();
        void set_background_color(float red, float green, float blue, float alpha);
        void update_window();
        int close_window();
        void terminate();
};

#endif