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

        unsigned int shaderProgram;
        /// vertex array object reference number
        unsigned int vao;
        /// GLFW window instance pointer
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

        /// vertex shader program
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
        
        /// fragment shader source program (monochrome)
        const char *fragmentShaderSource = 
            "#version 330 core\n"
            "out vec4 fragColor;\n"
            "in vec4 color;\n"
            "void main()\n"
            "{\n"
            "   fragColor = vec4(0.25f, 0.75f, 0.5f, 1.0f);\n"
            "}\n\0";
        
         /// fragment shader source program (gradient coloring based on `location`)
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
         * @brief Utility function to add a primitive
         * 
         * @param points Tightly packed array of integer coordinates representing the 
         * primitive
         * @param pointCount Number of points in `points`
         */
        void add_primitive(int* points, int pointCount);
        /**
         * @brief Utility function to plot a primitive
         * 
         * @param points Tightly packed array of integer coordinates representing the 
         * primitive
         * @param pointCount Number of points in `points`
         */
        void plot_points(const int* points, int pointCount);
        /**
         * @brief Utility function to normalize all points in `points` to [-1, 1]
         *  range. Normalization is done in place.
         * 
         * @param x, y, z coordinates to be normalized
         */
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
         * @brief Load a Line type object into `primitives`
         * 
         * @param line object to be added
         */
        void load_line(Line line);
        /**
         * @brief Load a Circle type object into `primitives`
         * 
         * @param circle object to be added
         */
        void load_circle(Circle circle);
        /**
         * @brief Load the points from `primitives` into vertex buffers for
         * plotting
         * 
         */
        void draw();
        /**
         * @brief Set the background color object
         * 
         * @param red, green, blue, alpha Color in RGBA format. All values are in [-1, 1] range
         */
        void set_background_color(float red, float green, float blue, float alpha);
        /**
         * @brief Reverse the plotting buffers and poll for any new events
         * 
         */
        void update_window();
        /**
         * @brief Check whether the command to terminate window was initiated
         * 
         * @return int 1 if window should be closed, 0 otherwise
         */
        int close_window();
        /**
         * @brief Triggers `glfwTerminate()` to neatly clean all OpenGL memory 
         * allocations
         * 
         */
        void terminate();
};

#endif