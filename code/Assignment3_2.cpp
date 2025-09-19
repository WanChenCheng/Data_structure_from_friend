#include <iostream>
#include <string>
#include <vector>

using namespace std;

typedef struct Node
{
    long long key, count;
    Node *left;
    Node *right;
    Node *parent;
    Node(long long _key, long long _count = 1, Node *_left = nullptr, Node *_right = nullptr, Node *_parent = nullptr)
        : key(_key), count(_count), left(_left), right(_right), parent(_parent) {}
} Node;

// Input:   The root node of the tree.
// Return:  The node with minimum value of the tree.
Node *findmin(Node *root)
{
    while (root->left)
        root = root->left;
    return root;
}

// Input:   The root node of the tree.
// Return:  The node with maximum value of the tree.
Node *findmax(Node *root)
{
    while (root->right)
        root = root->right;
    return root;
}

// Input:   The root node of the tree and the value we want to find.
// Return:  The node with the value. If the node doesn't exist, return nullptr.
Node *search(Node *root, long long k)
{
    if (root == nullptr)
        return nullptr;
    if (root->key == k)
        return root;
    if (root->key > k)
        return search(root->left, k);
    else
        return search(root->right, k);
}

// Input:   The root node of the tree we want to insert the node long longo.
void insertnode(Node *&root, Node *node)
{
    if (root == nullptr)
    {
        root = node;
        return;
    }
    if (root->key > node->key)
    {
        if (root->left)
        {
            insertnode(root->left, node);
        }
        else
        {
            root->left = node;
            node->parent = root;
        }
    }
    else if (root->key < node->key)
    {
        if (root->right)
        {
            insertnode(root->right, node);
        }
        else
        {
            root->right = node;
            node->parent = root;
        }
    }
    return;
}

// Transplant(root, x, y) links x's parent to y and y's parent is changed accordingly under the tree root
void transplant(Node *&root, Node *x, Node *y)
{
    if (x->parent == nullptr)
    {
        root = y;
    }
    else if (x->parent->left == x)
    {
        x->parent->left = y;
    }
    else
    {
        x->parent->right = y;
    }

    if (y)
    {
        y->parent = x->parent;
    }
    return;
}

// Input:   The root node of the tree and the node we want to delete
void deletenode(Node *&root, Node *x)
{
    /* Case 1: x is a leaf */
    if (x->left == nullptr && x->right == nullptr)
        transplant(root, x, nullptr);
    /* Case 2: x has one child */
    else if (x->left == nullptr)
        transplant(root, x, x->right);
    else if (x->right == nullptr)
        transplant(root, x, x->left);
    /* Case 3: x has two children */
    else
    {
        Node *y = findmin(x->right);
        if (y->parent == x)
        {
            transplant(root, x, y);
            y->left = x->left;
            x->left->parent = y;
        }
        else
        {
            transplant(root, y, y->right);
            transplant(root, x, y);
            y->right = x->right;
            y->left = x->left;
            x->right->parent = x->left->parent = y;
        }
    }
    free(x);
}

// Input:   The root node of the tree and the value of x
// Return:  The smallest element greater than or equal to x in the set.
//          If the value doesn't exist, return -1
long long findlowerbound(Node *root, long long x)
{
    long long ans = -1;
    if (x < root->key)
    {
        if (root->left != NULL)
            ans = findlowerbound(root->left, x);

        if (ans != -1)
            ans = min(root->key, ans);
        else
            ans = root->key;
    }
    else if (x > root->key)
    {
        if (root->right != NULL)
            ans = findlowerbound(root->right, x);
    }
    else /*(node -> key == x)*/
        ans = x;
    return ans;
}

// Input:   The root node of the tree and the value of x
// Return:  The smallest element greater than x in the set.
//          If the value doesn't exist, return -1
long long findupperbound(Node *root, long long x)
{
    long long ans = -1;
    if (x < root->key)
    {
        if (root->left != NULL)
            ans = findupperbound(root->left, x);

        if (ans != -1)
            ans = min(root->key, ans);
        else
            ans = root->key;
    }
    else /*if (x >= root -> key)*/
    {
        if (root->right != NULL)
            ans = findupperbound(root->right, x);
    }
    return ans;
}

int main()
{
    // TODO
    long long n;
    cin >> n;
    Node *root = nullptr;
    long long size = 0;

    while (n--)
    {
        char c;
        long long x;
        cin >> c >> x;

        switch (c)
        {
            case 'I':
            {
                if (search(root, x) == nullptr)
                {
                    size++;
                    Node *node = new Node(x);
                    insertnode(root, node);
                }
                else
                {
                    search(root, x)->count++;
                }
                cout << size << "\n";
                break;
            }
            case 'D':
            {
                if (search(root, x) != nullptr)
                {
                    if (search(root, x)->count == 1)
                    {
                        deletenode(root, search(root, x));
                        size--;
                    }
                    else
                    {
                        search(root, x)->count--;
                    }
                }
                cout << size << "\n";
                break;
            }
            case 'C':
                if (search(root, x) == nullptr)
                {
                    cout << "0\n";
                }
                else
                {
                    cout << search(root, x)->count << "\n";
                }
                break;
            case 'L':
                cout << findlowerbound(root, x) << "\n";
                break;
            case 'U':
                cout << findupperbound(root, x) << "\n";
                break;
            default:
                break;
        }
    }

    return 0;
}