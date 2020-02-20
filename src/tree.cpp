#include "tree.h"

Tree::Tree(std::vector<int> tree)
{
    tRoot = new Node;
    construct(1, tRoot, tree);
    minsep = 5;
    minX = -1, minY = 1, maxX = -1, maxY = 1;
    setup(tRoot, 0, nullptr, nullptr);
    petrify(tRoot, 0);
    normalize(tRoot);
}

void Tree::setup(Node* root, int currentLevel, Extreme* rightMost, Extreme* leftMost)
{
    Node *l, *r;
    Extreme* lr = new Extreme; lr -> node = new Node;
    Extreme* ll = new Extreme; ll -> node = new Node;
    Extreme* rr = new Extreme; rr -> node = new Node;
    Extreme* rl = new Extreme; rl -> node = new Node;
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
        if (maxX == 1)
            maxX = root -> x;
        else
            maxX = std::max(maxX, root -> x);
        if (minX == 1)
            minX = root -> x;
        else
            minX = std::min(minX, root -> x);
        if (root -> thread)
        {
            root -> thread = false;
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
        Node* newNode = new Node;
        node -> left = newNode;
        construct(2*idx, newNode, tree);
    }

    if (2*idx + 1 <= size && tree[2*idx + 1])
    {
        Node* newNode = new Node;
        node -> right = newNode;
        construct(2*idx + 1, newNode, tree);
    }
}

void Tree::normalize(Node* node)
{
    if (node -> left != nullptr)
        normalize(node -> left);
    
    node -> x = (node -> x - minX) * WIDTH / (maxX - minX);
    node -> y = (node -> y - minY) * HEIGHT / (maxY - minY);

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

/* DEBUG
// */

int main()
{
    std::vector<int> tree = {0, 1, 1, 1, 0, 1, 1, 0, 0, 0};
    Tree t(tree);
    t.display_tree_coordinates();
    return 0;
}