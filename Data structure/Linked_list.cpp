#include <iostream>
#include <memory>

using namespace std;

struct Node
{
	int value;
	shared_ptr<Node> next;

	Node(int value)
	{
		this->value = value;
		next = nullptr;
	}
};

class LinkedList
{
private:
	shared_ptr<Node> head;
	shared_ptr<Node> tail;
	int length;

public:
	LinkedList(int value)
	{
		shared_ptr<Node> newNode = make_shared<Node>(value);
		head = newNode;
		tail = newNode;
		length++;
	}

	void printList()
	{
		shared_ptr<Node> temp = head;

		while (temp)
		{
			cout << temp->value << " ";
			temp = temp->next;
		}
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

	void append(int value)
	{
		shared_ptr<Node> new_node = make_shared<Node>(value);
		tail->next = new_node;
		tail = new_node;
	}

	void delete_last()
	{

		if (length == 0)
			return;

		if (length == 1)
		{
			head = nullptr;
			tail = nullptr;
			return;
		}
		else
		{

			shared_ptr<Node> temp = head;

			while (temp->next->next)
			{
				temp = temp->next;
			}
			temp->next = nullptr;
			tail = temp;
		}
		length--;
	}

	void prepand(int value)
	{
		shared_ptr<Node> new_node = make_shared<Node>(value);
		if (length == 0)
		{
			head = new_node;
			tail = new_node;
		}
		else
		{
			new_node->next = head;
			head = new_node;
		}
		length++;
	}

	void delete_first()
	{
		if (length == 0)
			return;

		if (length == 1)
		{
			head = nullptr;
			tail = nullptr;
		}
		else
		{
			shared_ptr<Node> temp = head;
			head = head->next;
		}
		length--;
	}

	shared_ptr<Node> get(int index)
	{
		if ((index < 0) && (index > length))
		{
			return nullptr;
		}
		shared_ptr<Node> temp = head;
		for (int i = 0; i < index - 1; i++)
		{
			temp = temp->next;
		}
		return temp;
	}

	bool set(int index, int value)
	{
		shared_ptr<Node> temp = get(index);

		if (temp)
		{
			temp->value = value;
			return true;
		}
		return false;
	}

	bool insert(int index, int value)
	{
		if ((index < 0 || index >= length))
			return false;
		if (index == 0)
			prepand(value);
		return true;
		if (index == length)
			append(value);
		return true;

		shared_ptr<Node> new_node = make_shared<Node>(value);

		shared_ptr<Node> temp = get(index);
		new_node->next = temp;
		temp->next = new_node;
		length++;
		return true;
	}

	~LinkedList()
	{
	}
};

int main()
{
	shared_ptr<LinkedList> myLinkedList = make_shared<LinkedList>(4);
	cout << "\n\nAfter append" << endl;
	myLinkedList->append(6);
	myLinkedList->printList();

	cout << "\n\nAfter prepand" << endl;
	myLinkedList->prepand(10);
	myLinkedList->printList();

	cout << "\n\nAfter delete_first" << endl;
	myLinkedList->delete_first();
	myLinkedList->printList();

	cout << "\n\nGet the element at index 2: ";
	cout << myLinkedList->get(2)->value << endl;

	cout << "\nSet the value: ";
	myLinkedList->set(1, 4);
	myLinkedList->printList();

	cout << "\nInsert the value: ";
	myLinkedList->insert(1, 1);
	myLinkedList->printList();
}