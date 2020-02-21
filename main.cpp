/**
@file
*/
#include <iostream>
#include <vector>
#include "circle.h"
#include "graphics_engine.h"
#include "line.h"
#include "tree.h"

int main()
{
    GraphicsEngine engine = GraphicsEngine();
    GLFWwindow* window = engine.window;

    // engine.load_circle(Circle(50, 400, 10));
    // engine.load_circle(Circle(250, 50, 10));

    // std::vector<int> treeRep = {0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
    std::vector<int> treeRep (128);
    for (int i = 2; i <= 127; i *= 2)
        treeRep[i] = 1, treeRep[i - 1] = 1, treeRep[i + 1] = 1, treeRep[i - 2] = 1;
    treeRep[127] = treeRep[126] = 1;
    int parity = 0;
    Tree tree = Tree(treeRep);
    tree.display_tree_coordinates();
    std::vector<Circle> nodes = tree.get_nodes();
    std::vector<Line> edges = tree.get_edges();
    for (int i = 0; i < nodes.size(); i++)
        engine.load_circle(nodes[i]);
    for (int i = 0; i < edges.size(); i++)
        engine.load_line(edges[i]);


    // render loop
    while (!glfwWindowShouldClose(window))
    {
        // process all input before updating frame
        engine.process_input();

        // set color of window
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        // Drawing happens here.
        engine.draw();
        // engine.plot_points(points[1], pointCount[1]);

        // update window
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
    std::cout << "Ending program...\n";
    return 0;
}