/**
@file
*/
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include "screen.h"

/**
 * @brief A callback function to process any changes made to the 
 * screen size.
 * 
 * @param window pointer to the current window.
 * @param width, height current dimensions of the window.
 */
void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
    return;
} 

/**
 * @brief A callback function to process any I/O done by user
 * to the current window.
 * 
 * @param window pointer to the current window.
 */
void processInput(GLFWwindow* window)
{
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
    return;
}

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
 * 
 * @return GLFWwindow* pointer to the current window.
 */
GLFWwindow* initialize()
{
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    GLFWwindow* window = glfwCreateWindow(WIDTH, HEIGHT, "Window", NULL, NULL);
    if (window == NULL)
    {
        std::cout << "Failed to create window\n";
        glfwTerminate();
        exit(1);
    }
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
    glfwMakeContextCurrent(window);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to load GLAD\n";
        exit(1);
    }
    glViewport(0, 0, WIDTH, HEIGHT);

    return window;
}

int main()
{
    
    GLFWwindow* window = initialize();

    // render loop
    while (!glfwWindowShouldClose(window))
    {
        // process all input before updating frame
        processInput(window);

        // set color of window
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        /*
            Drawing happens here.
        */

        // update window
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
    std::cout << "Ending program...\n";
    return 0;
}