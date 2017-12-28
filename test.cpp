#include<iostream>
#include<vector>
using namespace std;

int main()
{
    vector<int> vec{1,2,3};
    //auto i = vec.back();
    vec.back() = 8;

    cout << vec[2] << endl;

    return 0;
}
