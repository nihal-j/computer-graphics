/**
@file
*/
#include <iostream>
#include <vector>
#include "circle.h"
#include "generator.h"
#include "graphics_engine.h"
#include "line.h"
#include "tree.h"

int main()
{
    GraphicsEngine engine = GraphicsEngine();

    std::vector<int> treeRep;    
    // treeRep = random_tree(5);
    // treeRep = {0, 1, 0, 0, 0};
    treeRep = complete_binary_tree(4);

    Tree tree = Tree(treeRep);
    std::vector<Circle> nodes = tree.get_nodes();
    std::vector<Line> edges = tree.get_edges();
    for (int i = 0; i < nodes.size(); i++)
        engine.load_circle(nodes[i]);
    for (int i = 0; i < edges.size(); i++)
        engine.load_line(edges[i]);


    // render loop
    while (!engine.close_window())
    {
        // process all input before updating frame
        engine.process_input();
        // set color of window
        engine.set_background_color(0.1f, 0.1f, 0.1f, 0.0f);
        // Drawing happens here.
        engine.draw();
        // update window
        engine.update_window();
    }

    engine.terminate();

    std::cout << "Ending program...\n";
    return 0;
}