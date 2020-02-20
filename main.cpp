/**
@file
*/
#include <iostream>

#include "circle.h"
#include "line.h"
#include "graphics_engine.h"

int main()
{
    GraphicsEngine engine;
    GLFWwindow* window = engine.window;

    const int n = 2;
    int *points[n];
    int pointCount[n];

    Circle circle(400, 400, 10);
    points[0] = circle.get_circle();
    pointCount[0] = circle.get_count();

    Line line = Line(408, 408, 450, 450);
    points[1] = line.get_line();
    pointCount[1] = line.get_count();
    // Circle circle1 = Circle(400, 400, 100);
    // points[1] = circle1.get_circle();
    // pointCount[1] = circle1.get_count();
    // Circle circle2 = Circle(500, 500, 200);
    // points[2] = circle2.get_circle();
    // pointCount[2] = circle2.get_count();

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