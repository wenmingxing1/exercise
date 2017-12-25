#include<vector>
#include<string>
#include<list>
#include<iostream>

using namespace std;

int main()
{
    list<char*> lc{"a", "an", "the"};
    vector<string> vec;
    vec.assign(lc.cbegin(), lc.cend()); // π”√assign

    for (auto str : vec)
        cout << str << endl;

    return 0;
}
