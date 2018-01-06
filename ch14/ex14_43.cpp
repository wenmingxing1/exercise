#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>

using namespace std;

int main()
{
    vector<int> vec{2,3,4,5,6};
    int input;
    cin >> input;
    modulus<int> mod;
    auto is_divisible = all_of(vec.begin(), vec.end(), [&](int i){return 0 == mod(input, i);});

    cout << (is_divisible? "Yes" : "No") << endl;

    return 0;
}
