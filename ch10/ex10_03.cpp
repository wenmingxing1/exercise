#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
    vector<int> vec{1,2,3};
    cout << accumulate(vec.cbegin(), vec.cend(), 0) << endl;

    vector<double> vec2{1.0, 2.1, 3.9};
    cout << accumulate(vec.cbegin(), vec.cend(), 0) << endl;

    return 0;
}
