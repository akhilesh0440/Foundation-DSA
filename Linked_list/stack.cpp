#include <iostream>

struct Node
{
    int value;
    Node *next;

    Node(int value)
    {
        this->value = value;
        this->next = nullptr;
    }
};

class Stack
{
private:
    Node *top;
    int height;

public:
    Stack(int value)
    {
        Node *newNode = new Node(value);
        top = newNode;
        height = 1;
    }

    void printStack()
    {
        Node *temp = top;
        while (temp)
        {
            std::cout << temp->value << " ";
            temp = temp->next;
        }
    }

    void getTop()
    {
        std::cout << "Top: " << top->value << std::endl;
    }

    void getHeight()
    {
        std::cout << "Height: " << height << std::endl;
    }

    void push(int value)
    {
        Node *newNode = new Node(value);
        newNode->next = top;
        top = newNode;
        height++;
    }

    int pop()
    {

        if (height == 0)
            return INT_MIN;

        Node *temp = top;
        int poppedValue = top->value;
        top = top->next;
        delete temp;
        height--;

        return poppedValue;
    }

    ~Stack()
    {
        while (top)
        {
            Node *temp = top;
            top = top->next;
            delete temp;
        }
    }
};

int main()
{
    Stack *myStack = new Stack(5);
    myStack->printStack();

    /* std::cout << "Popping two times" << std::endl;
    std::cout << "First Pop: " << myStack->pop() << std::endl;
    std::cout << "Second Pop: " << myStack->pop() << std::endl; */

    return 0;
}