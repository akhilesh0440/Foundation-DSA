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

class Queue
{
private:
    Node *first;
    Node *last;
    int length;

public:
    Queue(int value)
    {
        Node *newNode = new Node(value);
        first = last = newNode;
        length = 1;
    }

    void printQueue()
    {
        Node *temp = last;
        while (temp)
        {
            std::cout << temp->value << " ";
            temp = temp->next;
        }
        std::cout << std::endl;
    }

    void getLast()
    {
        std::cout << "Last: " << last->value << std::endl;
    }

    void getFirst()
    {
        std::cout << "First: " << first->value << std::endl;
    }

    void getLength()
    {
        std::cout << "Length: " << length << std::endl;
    }

    void enqueue(int value)
    {
        Node *newNode = new Node(value);
        newNode->next = last;
        last = newNode;
        if (length == 0)
            first = last;
        length++;
    }

    int dequeue()
    {
        if (length == 0)
            return INT_MIN;
        Node *temp = first;
        int dequeuedValue = first->value;
        if (length == 1)
        {
            first = last = nullptr;
        }
        else
        {
            first = first->next;
        }
        delete temp;
        length--;
        return dequeuedValue;
    }

    ~Queue()
    {
        Node *temp = last;
        while (temp)
        {
            last = last->next;
            delete temp;
        }
    }
};

int main()
{

    Queue *myQueue = new Queue(7);
    myQueue->printQueue();

    std::cout << "After enqueue: ";
    myQueue->enqueue(10);
    myQueue->printQueue();

    std::cout << "After dequeue: " << myQueue->dequeue() << std::endl;
    std::cout << "After dequeue: " << myQueue->dequeue() << std::endl;
    std::cout << "After dequeue: " << myQueue->dequeue() << std::endl;
    myQueue->printQueue();

    return 0;
}