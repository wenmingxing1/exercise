#include<iostream>
#include<list>
#include<deque>
using namespace std;

int main()
{
    list<int> li{1,2,3,4,5};
    deque<int> de1;
    deque<int> de2;

    list<int>::iterator iter = li.begin();

    while (iter != li.end()) {
        if (*iter % 2 == 1)
            de1.push_back(*iter);
        if (*iter % 2 == 0)
            de2.push_back(*iter);
        ++iter;
    }

    cout << "de1:" << endl;
    for (auto i : de1)
        cout << i << " ";
    cout << endl;
    cout << "de2:" << endl;
    for (auto i : de2)
        cout << i << " ";

    cout << endl;

    return 0;
}
