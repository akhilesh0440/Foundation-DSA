#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

bool itemInCommon(vector<int> vect1, vector<int> vect2)
{
    unordered_map<int, bool> myMap;
    for (auto i : vect1)
    {
        myMap.insert({i, true});
    }

    for (auto i : vect1)
    {
        if (myMap[i])
            return true;
    }
}

int main()
{
    vector<int> vect1{1, 3, 5};
    vector<int> vect2{2, 4, 5};

    cout << itemInCommon(vect1, vect2);

    return 0;
}