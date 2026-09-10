#include <iostream>

using namespace std;
struct Node
{
    int value;
    Node *next;
    Node *prev;

    Node(int value)
    {
        this->value = value;
        this->next = nullptr;
        this->prev = nullptr;
    }
};

class DoublyLinkedList
{
private:
    Node *head;
    Node *tail;
    int length;

public:
    DoublyLinkedList(int value)
    {
        Node *newNode = new Node(value);
        head = newNode;
        tail = newNode;
        length++;
    }

    void getHead()
    {
        cout << "Head: " << head->value << endl;
    }

    void getTail()
    {
        cout << "Tail: " << tail->value << endl;
    }

    void getLength()
    {
        cout << "Length: " << length << endl;
    }

    void printList()
    {
        Node *temp = head;
        while (temp)
        {
            cout << temp->value << " ";
            temp = temp->next;
        }
    }

    void append(int value)
    {
        Node *newNode = new Node(value);
        if (!head)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
        }
        length++;
    }

    void DeleteLast()
    {
        if (!head)
            return;

        Node *temp = tail;
        if (length == 1)
        {
            head = tail = nullptr;
        }
        else
        {
            tail = tail->prev;
            tail->next = nullptr;
        }
        delete temp;
        length--;
    }

    void prepand(int value)
    {
        Node *newNode = new Node(value);
        if (!head)
            head = tail = newNode;
        else
        {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
        length++;
    }

    void deleteFirst()
    {
        if (!head)
            return;
        Node *temp = head;
        if (length == 1)
            head = tail = nullptr;
        else
        {
            head = head->next;
            head->prev = nullptr;
        }
        length--;
        delete temp;
    }

    Node *get(int index)
    {
        if (index < 0 || index > length)
            return nullptr;
        Node *temp = head;
        if (index < length / 2)
        {
            for (int i = 0; i < index; i++)
            {
                temp = temp->next;
            }
        }
        else
        {
            temp = tail;
            for (int i = length - 1; i > index; i--)
            {
                temp = temp->prev;
            }
        }
        return temp;
    }

    bool set(int index, int value)
    {
        Node *temp = get(index);
        if (temp)
        {
            temp->value = value;
            return true;
        }
        return false;
    }

    bool insert(int index, int value)
    {
        if (index < 0 || index > length)
            return false;
        if (index == 0)
        {
            prepand(value);
            return true;
        }
        if (index == length)
        {
            append(value);
            return true;
        }
        Node *newNode = new Node(value);
        Node *before = get(index - 1);
        Node *after = before->next;

        before->next = newNode;
        after->prev = newNode;

        newNode->prev = before;
        newNode->next = after;
        length++;

        return true;
    }

    void deleteNode(int index)
    {
        if (index < 0 || index > length)
            return;
        if (index == 0)
        {
            deleteFirst();
            return;
        }
        if (index == length - 1)
        {
            DeleteLast();
            return;
        }
        Node *temp = get(index);
        temp->next->prev = temp->prev;
        temp->prev->next = temp->next;

        delete temp;
        length--;
    }
};

int main()
{
    DoublyLinkedList *myDLL = new DoublyLinkedList(7);
    cout << "\nAfter append 10 : ";
    myDLL->append(2);
    myDLL->append(3);
    myDLL->append(4);
    myDLL->append(5);
    myDLL->printList();

    /* cout << "\nAfter DeleteLast: ";
    myDLL->DeleteLast();
    myDLL->printList(); */

    /* cout << "\nAfter prepand: ";
    myDLL->prepand(111);
    myDLL->printList(); */

    /*cout << "\nAfter Delete First: ";
    myDLL->deleteFirst();
    myDLL->printList(); */

    /* cout << "\nAfter set: index 2, value 33: ";
    myDLL->set(2, 33);
    myDLL->printList(); */

    /* cout << "\nAfter insert: index 3, value 63: ";
    myDLL->insert(3, 63);
    myDLL->printList(); */

    /* cout << "\nDelete at first Node: ";
    myDLL->deleteNode(0);
    myDLL->printList(); */

    /* cout << "\nDelete at last Node: ";
    myDLL->deleteNode(4);
    myDLL->printList(); */

    /* cout << "\nDelete at first Node: ";
    myDLL->deleteNode(3);
    myDLL->printList(); */

    return 0;
}