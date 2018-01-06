#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<functional>

using namespace std;

int main()
{
    using placeholders::_1;

    vector<int> vec{1, 11, 111, 1111, 11111};
    int count = count_if(vec.cbegin(), vec.cend(), bind(greater<int>(), _1, 1024));
    //int count = count_if(vec.cbegin(), vec.cend(), [](int i){return i >= 1024;}); //以lambda表达式完成
    cout << count << endl;

    vector<string> svec{ "pooh", "pooh", "ligang", "pooh" };
    auto found = find_if(svec.cbegin(), svec.cend(), bind(not_equal_to<string>(), _1, "pooh"));
    cout << *found << endl;

    transform(vec.begin(), vec.end(), vec.begin(), bind(multiplies<int>(), _1, 2));
    for (auto i : vec)
        cout << i << " ";

    cout << endl;

    return 0;
}
