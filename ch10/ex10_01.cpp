#include<iostream>
#include<vector>
#include<algorithm>
#include<list>
#include<string>

using namespace std;

int main()
{
    vector<int> vec{1,2,3,3,3,4,5,3,5};
    cout << count(vec.cbegin(), vec.cend(), 3) << endl;

    list<string> li{ "a", "an", "a", "the" };
    cout << count(li.cbegin(), li.cend(), "a") << endl;

    return 0;
}
