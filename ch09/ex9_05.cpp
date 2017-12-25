#include<iostream>
#include<vector>
using namespace std;

using iter = vector<int>::iterator;

iter Find(iter iter1, iter iter2, int num) {
    bool res = false;
    while (iter1 != iter2) {
        if (*iter1 == num)
            return iter1;
        ++iter1;
    }

    if (iter1 == iter2)
        cout << "no match" << endl;
    return iter2;
}

int main()
{
    vector<int> vec{1,2,3,4,5};

    cout << *Find(vec.begin(), vec.end(), 6) << endl;

    return 0;
}
