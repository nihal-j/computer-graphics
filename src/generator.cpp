#include <iostream>
#include "generator.h"

std::vector<int> complete_binary_tree(int depth)
{
    // depth starts from 0
    std::vector<int> tree = {0};
    int curr = 0;
    int max = 1 << depth;
    for (int i = 1; i < max; i++)
        tree.push_back(1);
    return tree;
}

std::vector<int> random_tree(int depth)
{
    srand(time(0));
    std::vector<int> tree;
    // depth starts from zero
    tree.push_back(0);
    tree.push_back(1);
    int cnt = (1 << (depth + 1)) - 2;
    for (int i = 2; i <= cnt && i/2 < tree.size(); i++)
    {
        float prob = (float)rand() / RAND_MAX;
        // std::cout << prob << "\n";
        if (prob <= 0.5 && tree[i/2])
            tree.push_back(1);
        else
            tree.push_back(0);        
    }
    
    return tree;
}

/* DEBUG
// /

int main()
{
    std::vector<int> tree = random_tree(5);
    for (int i = 0; i < tree.size(); i++)
        std::cout << tree[i] << " ";    
    return 0;
}

// */