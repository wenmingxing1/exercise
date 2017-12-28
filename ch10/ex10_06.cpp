#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main()
{
    vector<int> vec{1,2,3};

    cout << "the original:" << endl;
    for (auto i : vec)
        cout << i << " ";

    fill_n(vec.begin(), vec.size(), 0);

    cout << endl;
    cout << "after change:" << endl;
    for (auto i : vec)
        cout << i << " ";

    return 0;
}
