#include <iostream>
#include "tree.h"

Tree::Tree(std::vector<int> tree)
{
    tRoot = create_node();
    construct(1, tRoot, tree);
    minsep = 5;
    minX = -1, minY = 1, maxX = -1, maxY = 1;
    setup(tRoot, 0, nullptr, nullptr);
    // traverse(tRoot);
    petrify(tRoot, 0);
    // traverse(tRoot);
    normalize(tRoot);
    make_primitives();
}

void Tree::setup(Node* root, int currentLevel, Extreme* rightMost, Extreme* leftMost)
{
    Node *l, *r;
    Extreme* lr = create_extreme();
    Extreme* ll = create_extreme();
    Extreme* rr = create_extreme();
    Extreme* rl = create_extreme();
    int cursep, rootsep, loffsum, roffsum;

    if (root == nullptr)
    {
        leftMost -> level = -1;
        rightMost -> level = -1;
    }

    else
    {
        root -> y = currentLevel * -1;
        if (maxY == 1)
            maxY = root -> y;
        else
            maxY = std::max(maxY, root -> y);
        if (minY == 1)
            minY = root -> y;
        else
            minY = std::min(minY, root -> y);
        l = root -> left;
        r = root -> right;
        setup(l, currentLevel + 1, lr, ll);
        setup(r, currentLevel + 1, rr, rl);

        if (r == nullptr && l == nullptr)
        {
            rightMost -> node = root;
            leftMost -> node = root;
            rightMost -> level = currentLevel;
            leftMost -> level = currentLevel;
            rightMost -> offset = 0;
            leftMost -> offset = 0;
            root -> offset = 0;
        }

        else
        {
            cursep = rootsep = minsep;
            loffsum = roffsum = 0;

            while (l != nullptr && r != nullptr)
            {
                if (cursep < minsep)
                {
                    rootsep = rootsep + minsep - cursep;
                    cursep = minsep;
                }

                if (l -> right != nullptr)
                {
                    loffsum += l -> offset;
                    cursep -= l -> offset;
                    l = l -> right;
                }
                else
                {
                    loffsum -= l -> offset;
                    cursep += l -> offset;
                    l = l -> left;
                }

                if (r -> left != nullptr)
                {
                    roffsum -= r -> offset;
                    cursep -= r -> offset;
                    r = r -> left;
                }
                else
                {
                    roffsum += r -> offset;
                    cursep += r -> offset;
                    r = r -> right;
                }
            }

            root -> offset = (rootsep + 1) / 2;
            loffsum -= root -> offset;
            roffsum += root -> offset;

            if ((rl -> level > ll -> level) || (root -> left == nullptr))
            {
                leftMost = rl;
                leftMost -> offset += root -> offset;
            }
            else
            {
                leftMost = ll;
                leftMost -> offset -= root -> offset;
            }

            if ((lr -> level > rr -> level) || (root -> right == nullptr))
            {
                rightMost = lr;
                rightMost -> offset -= root -> offset;
            }
            else
            {
                rightMost = rr;
                rightMost -> offset += root -> offset;
            }

            if (l != nullptr && l != root -> left)
            {
                rr -> node -> thread = 1;
                rr -> node -> offset = abs(rr -> offset + root -> offset - loffsum);
                if (loffsum - root -> offset <= rr -> offset)
                    rr -> node -> left = l;
                else
                    rr -> node -> right = l;
            }
            else if (r != nullptr && r != root -> right)
            {
                ll -> node -> thread = 1;
                ll -> node -> offset = abs(ll -> offset - root -> offset - roffsum);
                if (roffsum + root -> offset >= ll -> offset)
                    ll -> node -> right = r;
                else
                    ll -> node -> left = r;                
            }
        }
    }
}

void Tree::petrify(Node* root, int xpos)
{
    if (root != nullptr)
    {
        root -> x = xpos;
        if (maxX == -1)
            maxX = root -> x;
        else
            maxX = std::max(maxX, root -> x);
        if (minX == -1)
            minX = root -> x;
        else
            minX = std::min(minX, root -> x);
        if (root -> thread)
        {
            root -> thread = 0;
            root -> right = nullptr;
            root -> left = nullptr;
        }
        petrify(root -> left, xpos - root -> offset);
        petrify(root -> right, xpos + root -> offset);
    }
}

void Tree::construct(int idx, Node* node, std::vector<int> &tree)
{
    int size = tree.size() - 1;
    if (2*idx <= size && tree[2*idx])
    {
        node -> left = create_node();
        construct(2*idx, node -> left, tree);
    }

    if (2*idx + 1 <= size && tree[2*idx + 1])
    {
        node -> right = create_node();
        construct(2*idx + 1, node -> right, tree);
    }
}

Node* Tree::create_node()
{
    Node* node = new Node;
    node -> left = nullptr;
    node -> right = nullptr;
    node -> offset = 0;
    node -> x = node -> y = 0;
    node -> thread = 0;
    return node;
}

Extreme* Tree::create_extreme()
{
    Extreme* ext = new Extreme;
    ext -> node = create_node();
    ext -> offset = 0;
    ext -> level = 0;
}

void Tree::normalize(Node* node)
{
    if (node -> left != nullptr)
        normalize(node -> left);
    
    int pad = 50;

    int a = pad;
    int b = WIDTH - pad;
    /*
            x - mx       x' - a
            -------  =  --------
            Mx - mx      b - a
    */
    node -> x = ((node -> x - minX) * (b - a) / (maxX - minX)) + a;

    a = pad;
    b = HEIGHT - pad;
    node -> y = ((node -> y - minY) * (b - a)/ (maxY - minY)) + a;

    if (node -> right != nullptr)
        normalize(node -> right);
}

void Tree::traverse(Node* node)
{
    if (node -> left != nullptr)
        traverse(node -> left);
    std::cout << node -> x << ", " << node -> y << '\n';
    if (node -> right != nullptr)
        traverse(node -> right);
}

void Tree::display_tree_coordinates()
{
    traverse(tRoot);
}

void Tree::make_primitives()
{
    std::queue<Node*> q;
    q.push(tRoot);

    int radius = 5;

    while (!q.empty())
    {
        Node* curr = q.front();
        nodes.push_back(Circle(curr -> x, curr -> y, radius));
        int startX = curr -> x;
        int startY = curr -> y - radius;
        int endX, endY;
        if (curr -> left != nullptr)
        {
            endX = curr -> left -> x;
            endY = curr -> left -> y + radius;
            edges.push_back(Line(endX, endY, startX, startY));
            q.push(curr -> left);
        }
        if (curr -> right != nullptr)
        {
            endX = curr -> right -> x;
            endY = curr -> right -> y + radius;
            edges.push_back(Line(startX, startY, endX, endY));
            q.push(curr -> right);
        }
        q.pop();
    }
}

std::vector<Circle> Tree::get_nodes()
{
    return nodes;
}

std::vector<Line> Tree::get_edges()
{
    return edges;
}

/* DEBUG
// /

int main()
{
    std::vector<int> treeRep = {0};
    for (int i = 1; i <= 100; i++)
        treeRep.push_back(1);
    // std::vector<int> treeRep = {0, 1, 1, 1, 1, 1, 1, 1, 1};
    Tree t(treeRep);
    t.display_tree_coordinates();
    return 0;
}

// */