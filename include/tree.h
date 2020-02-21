#ifndef TREE_H
#define TREE_H

#include <vector>
#include <queue>
#include "circle.h"
#include "line.h"
#include "screen.h"
#include "types.h"

class Tree
{
    private:
        Node* tRoot;
        int minsep;
        int minX, minY, maxX, maxY;
        std::vector<Circle> nodes;
        std::vector<Line> edges;

        void setup(Node* root, int currentLevel, Extreme* rightMost, Extreme* leftMost);
        void petrify(Node* root, int xpos);
        void construct(int idx, Node* node, std::vector<int> &tree);
        void normalize(Node* node);
        void traverse(Node* node);
        Node* create_node();
        Extreme* create_extreme();
        void make_primitives();
        
    public:
        Tree(std::vector<int> tree);
        void display_tree_coordinates();
        std::vector<Circle> get_nodes();
        std::vector<Line> get_edges();
};

#endif