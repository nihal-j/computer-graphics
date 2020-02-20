/**
 * @file
 * 
 */

/**
 * @brief 
 * 
 */
struct Node
{
    Node* left;
    Node* right;
    int x, y;
    int offset;
    int thread;
};

/**
 * @brief 
 * 
 */
struct Extreme
{
    Node* node;
    int offset;
    int level;
};