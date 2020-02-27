/**
 * @file
 */
#include <vector>
#include <time.h>

/**
 * @brief Generates a complete binary tree with `depth` number of levels. Level count
 * starts from 0
 * 
 * @param depth depth of the binary tree
 * @return std::vector<int> binary tree representation in level order indexing
 */
std::vector<int> complete_binary_tree(int depth);
/**
 * @brief Generates a random binary tree with `depth` number of levels. Level count
 * starts from 0
 * @param depth depth of the binary tree
 * @return std::vector<int> binary tree representation in level order indexing
 */
std::vector<int> random_tree(int depth);