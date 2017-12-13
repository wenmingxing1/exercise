#include<iostream>
#include<vector>
using namespace std;

int main()
{
    vector<int> vec;
    int i;
    int count = 9;
    while (cin >> i && count > 0){
        vec.push_back(i);
        --count;
    }

    for (int j = 0; j < vec.size(); ++j)
        cout << vec[j] << " ";

    return 0;
}
