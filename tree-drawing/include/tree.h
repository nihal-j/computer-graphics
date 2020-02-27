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
        /// root of the tree
        Node* tRoot;
        /// MINSEP parameter specifies the minimum separation between the nodes allowed
        int minsep;
        /// coordinates of leftmost (x), rightmost (x), bottommost (y) and topmost (y)
        int minX, minY, maxX, maxY;
        /// collection of `Circle` objects indicating node positions in tree
        std::vector<Circle> nodes;
        /// collection of `Line` objects indicating edge positions in tree
        std::vector<Line> edges;

        /**
         * @brief procedure SETUP finds the coordinates following 4 important 
         * aesthetics for every node in the tree
         * 
         * @param root current node
         * @param currentLevel current level
         * @param rightMost rightMost vertex in current subtree
         * @param leftMost leftMost vertex in current subtree
         */
        void setup(Node* root, int currentLevel, Extreme* rightMost, Extreme* leftMost);
        /**
         * @brief procedure PETRIFY converts relative coordinates to absolute 
         * coordinates
         * 
         * @param root current node 
         * @param xpos x coordinate of current node to be passed on to children
         */
        void petrify(Node* root, int xpos);
        /**
         * @brief construct a tree from the vectorized level order representation.
         * Performs inorder traversal
         * @param idx idx of current node in `tree`
         * @param node current node
         * @param tree level order representation of the tree
         */
        void construct(int idx, Node* node, std::vector<int> &tree);
        /**
         * @brief Utility function to convert coordinates to fit the screen. Performs 
         * inorder traversal. Uses `WIDTH` and `HEIGHT` for normalizing.
         * 
         * @param node current node
         */
        void normalize(Node* node);
        /**
         * @brief Utility function to print tree. Performs inorder traversal
         * @param node current node
         */
        void traverse(Node* node);
        /**
         * @brief Create a node object
         * 
         * @return Node* object created
         */
        Node* create_node();
        /**
         * @brief Create a extreme object
         * 
         * @return Extreme* object created
         */
        Extreme* create_extreme();
        /**
         * @brief Construct `edges` and `nodes` from every coordinate generated after
         * `petrify()`
         * 
         */
        void make_primitives();
        void display_leaves(Node* node);
        
    public:
        /**
         * @brief Construct a new Tree object
         * 
         * @param tree object created
         */
        Tree(std::vector<int> tree);
        /**
         * @brief Display the coordinates of each node in the tree. Performs 
         * inorder traversal.
         * 
         */
        void display_tree_coordinates();
        /**
         * @brief Get the nodes object
         * 
         * @return std::vector<Circle> 
         */
        std::vector<Circle> get_nodes();
        /**
         * @brief Get the edges object
         * 
         * @return std::vector<Line> 
         */
        std::vector<Line> get_edges();
};

#endif