/**
 * @file
 * Specification of `Node` and `Extreme` as described in the paper.
 */

struct Node
{
    Node* left;
    Node* right;
    int x, y;
    int offset;
    int thread;
};

struct Extreme
{
    Node* node;
    int offset;
    int level;
};