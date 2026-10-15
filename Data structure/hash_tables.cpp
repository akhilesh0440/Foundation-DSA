#include <iostream>
#include <vector>

using namespace std;
/*
when hasing takes places, the key will convert into
address and store the value in that address

when we reading(get), this will too goes under hashing
and the read the value in that address
*/

/*
Collision: when key value pair override with other key value pair
            Linear chaining will be taken over in this scenario
            where it starts searching the adress linearly where it has empty space
            once it found empty space it will place the data in that address
*/

struct Node
{
    string key;
    int value;
    Node *next;

    Node(string inkey, int invalue) : key(inkey), value(invalue), next(nullptr) {}
};

class HashTable
{
private:
    static const int SIZE = 7;
    Node *dataMap[SIZE];

public:
    void printTable()
    {
        for (int i = 0; i < SIZE; i++)
        {
            cout << i << ":" << endl;
            if (dataMap[i])
            {
                Node *temp = dataMap[i];
                while (temp)
                {
                    cout << " {" << temp->key << ", " << temp->value << "}" << endl;
                    temp = temp->next;
                }
            }
        }
    }

    void set(string key, int value)
    {
        int index = hash(key);
        Node *newNode = new Node(key, value);
        if (dataMap[index] == nullptr)
            dataMap[index] = newNode;
        else
        {
            Node *temp = dataMap[index];
            while (temp->next != nullptr)
            {
                temp = temp->next;
            }

            temp->next = newNode;
        }
    }

    Node *get(string key)
    {
        int index = hash(key);

        Node *temp = dataMap[index];
        while (temp != nullptr && temp->key != key)
        {
            temp = temp->next;
        }
        return temp;
    }

    vector<string> keys()
    {
        vector<string> keys;
        for (int i = 0; i < SIZE; i++)
        {
            Node *temp = dataMap[i];
            while (temp)
            {
                keys.push_back(temp->key);
                temp = temp->next;
            }
        }
        return keys;
    }

    int hash(string key)
    {
        int hash = 0;
        for (int i = 0; i < 2; i++)
        {
            int asciiValue = int(key[i]);
            hash = (hash + asciiValue * 23) % SIZE;
        }
        return hash;
    }
};

int main()
{
    HashTable *myHashTable = new HashTable();

    myHashTable->set("nails", 100);
    myHashTable->set("tile", 50);
    myHashTable->set("lumber", 80);

    myHashTable->set("bolts", 200);
    myHashTable->set("screw", 140);

    myHashTable->printTable();

    Node *getValue = myHashTable->get("tiles");
    if (getValue)
        cout << "tiles ==> " << getValue->key << ":" << getValue->value << endl;
    else
        cout << "Value not found in the has Map" << endl;

    cout << endl;

    for (auto &key : myHashTable->keys())
    {
        cout << key << endl;
    }

    return 0;
}