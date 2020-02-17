/**
@file
*/
#include <iostream>

#include "graphics_engine.h"
#include "line.h"

int main()
{
    GraphicsEngine engine;
    GLFWwindow* window = engine.window;

    Line line(0, 0, 200, 200);
    float* points = line.get_line();
    int pointCount = line.get_count();

    for (int i = 0; i < 10; i++)
        std::cout << points[i*3] << " " << points[i*3 + 1] << " " << points[i*3 + 2] << "\n";
    std::cout << "\n";
    for (int i = pointCount - 1; i >= pointCount - 10; i--)
        std::cout << points[i*3] << " " << points[i*3 + 1] << " " << points[i*3 + 2] << "\n";

    // render loop
    while (!glfwWindowShouldClose(window))
    {
        // process all input before updating frame
        engine.processInput();

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