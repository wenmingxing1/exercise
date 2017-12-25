#include<iostream>
#include<vector>
using namespace std;

using iter = vector<int>::iterator;

bool Find(iter iter1, iter iter2, int num) {
    bool res = false;
    while (iter1 != iter2) {
        if (*iter1 == num)
            return true;
        ++iter1;
    }
    return res;
}

int main()
{
    vector<int> vec{1,2,3,4,5};

    if (Find(vec.begin(), vec.end(), 5))
        cout << "true" << endl;
    else
        cout << "false" << endl;

    return 0;
}
