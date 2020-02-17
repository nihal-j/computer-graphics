#ifndef GRAPHICS_ENGINE_H
#define GRAPHICS_ENGINE_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>

class GraphicsEngine
{
    private:

        ///
        unsigned int shaderProgram;
        ///
        unsigned int vao;

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
            "void main()\n"
            "{\n"
            "   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0f);\n"
            "}\n\0";
        
        ///
        const char *fragmentShaderSource = 
            "#version 330 core\n"
            "out vec4 fragColor;\n"
            "void main()\n"
            "{\n"
            "    fragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
            "}\n\0";


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
    void processInput();

    ///
    GLFWwindow* window;
};

#endif