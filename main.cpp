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

    Line line1(0, 0, 200, 200);
    int* points1 = line1.get_line();
    int pointCount1 = line1.get_count();

    Line line2(400, 400, 600, 500);
    int* points2 = line2.get_line();
    int pointCount2 = line2.get_count();

    Line line3(300, 300, 500, 1000);
    int* points3 = line3.get_line();
    int pointCount3 = line3.get_count();

    // render loop
    while (!glfwWindowShouldClose(window))
    {
        // process all input before updating frame
        engine.process_input();

        // set color of window
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        // Drawing happens here.
        engine.plot_points(points1, pointCount1);
        engine.plot_points(points2, pointCount2);
        engine.plot_points(points3, pointCount3);

        // update window
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
    std::cout << "Ending program...\n";
    return 0;
}