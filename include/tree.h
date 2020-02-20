#ifndef TREE_H
#define TREE_H

#include <iostream>
#include <vector>
#include <stdlib.h>
#include "screen.h"
#include "types.h"

class Tree
{
    private:
        Node* tRoot;
        int minsep;
        int minX, minY, maxX, maxY;

        void setup(Node* root, int currentLevel, Extreme* rightMost, Extreme* leftMost);
        void petrify(Node* root, int xpos);
        void construct(int idx, Node* node, std::vector<int> &tree);
        void normalize(Node* node);
        void traverse(Node* node);
        
    public:
        Tree(std::vector<int> tree);
        void display_tree_coordinates();
};

#endif