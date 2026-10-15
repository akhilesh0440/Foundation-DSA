#include <iostream>
#include <queue>

struct Node
{
    int value;
    Node *right;
    Node *left;
    Node(int value)
    {
        this->value = value;
        this->right = nullptr;
        this->left = nullptr;
    }
};

class BST
{
public:
    Node *root;

    BST()
    {
        root = nullptr;
    }

    void insert(int value)
    {
        /*
        1. Compare the value with root node value
        2. if it > go right else go left
        3. if nullptr insert newNode else move to next
        4. using while loop make sense
        5. temp = root and travese through the treek
        6. if root = nullptr , root = newNode
        7. In binary tree if the value == any of the value return fasle
        because in binary tree we can't have duplicate value

        temp = root
        while loop
                if root = nullptr , root = newNode
                if it > go right else go left
                if root = nullptr , root = newNode
        */
        Node *newNode = new Node(value);
        if (root == nullptr)
        {
            root = newNode;
            return;
        }

        Node *temp = root;
        while (true)
        {
            if (value == temp->value)
                return;
            if (value > temp->value)
            {
                if (temp->right == nullptr)
                {
                    temp->right = newNode;
                }
                temp = temp->right;
            }
            else
            {
                if (temp->left == nullptr)
                {
                    temp->left = newNode;
                }
                temp = temp->left;
            }
        }
    }

    bool contains(int value)
    {
        Node *temp = root;
        while (temp)
        {
            if (value < temp->value)
            {
                temp = temp->left;
            }
            else if (value > temp->value)
            {
                temp = temp->right;
            }
            else
            {
                return true;
            }
        }
        return false;
    }

    ~BST()
    {
    }
};

int main()
{

    BST *myBST = new BST();
    myBST->insert(47);
    myBST->insert(21);
    myBST->insert(76);
    myBST->insert(18);
    myBST->insert(52);
    myBST->insert(82);
    myBST->insert(27);

    std::cout << "Find the value 27: " << myBST->contains(27) << std::endl;
    std::cout << "Find the value 17: " << myBST->contains(17) << std::endl;

    // std::cout << myBST->root->left->right->value << std::endl;

    return 0;
}