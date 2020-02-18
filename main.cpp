/**
@file
*/
#include <iostream>

#include "line.h"
#include "graphics_engine.h"

int main()
{
    GraphicsEngine engine;
    GLFWwindow* window = engine.window;

    // Butterfly shape
    const int n = 5;
    Line lines[n] = {
        {200, 200, 600, 600},
        {200, 300, 600, 500},
        {200, 400, 600, 400},
        {200, 500, 600, 300},
        {200, 600, 600, 200},
    };
    int *points[n], pointCount[n];
    for (int i = 0; i < n; i++)
        points[i] = lines[i].get_line(), pointCount[i] = lines[i].get_count();

    for (int i = 0; i < n; i++)
    {
        std::cout << "Line " << i << "\n";
        lines[i].print_line(pointCount[i] - 10, 10);
    }

    // render loop
    while (!glfwWindowShouldClose(window))
    {
        // process all input before updating frame
        engine.process_input();

        // set color of window
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        // Drawing happens here.
        for (int i = 0; i < n; i++)
            engine.plot_points(points[i], pointCount[i]);

        // update window
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
    std::cout << "Ending program...\n";
    return 0;
}