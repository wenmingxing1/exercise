#include<iostream>
#include<vector>
#include<string>
#include<fstream>
#include<algorithm>
using namespace std;

bool isShorter(const string& str1, const string& str2) {
    return str1.size() < str2.size();
}

int main()
{
    fstream ifs("./data/input.txt");
    vector<string> vec;
    string word;
    while (ifs >> word)
        vec.push_back(word);

    cout << "The original:" << endl;
    for (auto str :  vec)
        cout << str << " ";

    stable_sort(vec.begin(), vec.end(), isShorter);

    cout << endl;
    cout << "After change:" << endl;
    for (auto str : vec)
        cout << str << " ";

    return 0;


}
