#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<fstream>
using namespace std;

int main()
{
    ifstream ifs("./data/input.txt");
    ofstream out("./data/output.txt");
    vector<string> vec;
    string word;
    while (ifs >> word)
        vec.push_back(word);

    /*
    for (auto str :  vec)
        cout << str << endl;
    */

    sort(vec.begin(), vec.end());
    auto iter = unique(vec.begin(), vec.end());

    vec.erase(iter, vec.end()); //erase是容器操作，不是算法

    for (auto str:vec)
        out << str << " ";



    return 0;
}
