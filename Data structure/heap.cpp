#include <iostream>
#include <vector>

using namespace std;

class Heap
{
private:
    vector<int> heap;

    int parent(int index)
    {
        return (index - 1) / 2;
    }

    int leftChild(int index)
    {
        return 2 * index + 1;
    }

    int rightChild(int index)
    {
        return 2 * index + 2;
    }

    void swap(int index1, int index2)
    {
        int temp = heap[index1];
        heap[index1] = heap[index2];
        heap[index2] = temp;
    }

public:
    void printHeap()
    {
        cout << "\n[";
        for (size_t i = 0; i < heap.size(); i++)
        {
            cout << heap[i];
            if (i < heap.size() - 1)
            {
                cout << ", ";
            }
        }
        cout << "]" << endl;
    }

    void insert(int value)
    {
        heap.push_back(value);
        int current = heap.size() - 1;

        while (current > 0 && heap[current] > heap[parent(current)])
        {
            swap(current, parent(current));
            current = parent(current);
        }
    }

    void sinkDown(int index)
    {
        int maxIndex = index;

        while (true)
        {
            int left = leftChild(index);
            int right = rightChild(index);

            if (left < heap.size() && heap[left] > heap[maxIndex])
            {
                maxIndex = left;
            }

            if (right < heap.size() && heap[right] > heap[maxIndex])
            {
                maxIndex = right;
            }

            if (maxIndex != index)
            {
                swap(index, maxIndex);
                index = maxIndex;
            }
            else
            {
                return;
            }
        }
    }

    int remove()
    {
        if (heap.empty())
        {
            return INT_MIN;
        }

        int maxValue = heap.front();

        if (heap.size() == 1)
        {
            heap.pop_back();
        }
        else
        {
            heap[0] = heap.back();
            heap.pop_back();
            sinkDown(0);
        }

        return maxValue;
    }
};

/*int main()
{
    Heap *myHeap = new Heap();
    myHeap->insert(95);
    myHeap->insert(75);
    myHeap->insert(80);
    myHeap->insert(55);
    myHeap->insert(60);
    myHeap->insert(50);
    myHeap->insert(65);

    myHeap->printHeap();

    myHeap->remove();

    myHeap->printHeap();

    myHeap->remove();

    myHeap->printHeap();

    return 0;
}*/

int main()
{

    while (true)
    {
        static int i = 0;
        cout << i << endl;
    }
    return 0;
}