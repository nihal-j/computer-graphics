#include <iostream>
#include "generator.h"

std::vector<int> complete_binary_tree(int depth)
{
    // depth starts from 0
    std::vector<int> tree = {0};
    int curr = 0;
    int max = 1 << (depth + 1);
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
    int cnt = (1 << (depth + 1)) - 1;
    float probability = 0.6f;

    int sign = -1;

    for (int i = 2; i <= cnt; i++)
    {
        // std::cout << probability << "\n";
        float prob = (float)rand() / RAND_MAX;
        if (prob <= probability && tree[i/2])
            tree.push_back(1);
        else
            tree.push_back(0);
        int t = i, flag = 0;
        while (t)
        {
            if (!(t&1))
                flag++;
            t >>= 1;
        }
        // if (!flag)
        //     probability += sign*0.1f;
        // if (probability <= 0.1f)
        //     sign = 1;
        // std::cout << probability << "\n";
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