#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<fstream>

using namespace std;

bool longerThanFive(const string& str) {
    return str.size() >= 5;
}

int main()
{
    ifstream ifs("./data/input.txt");
    vector<string> vec;
    string word;
    while (ifs >> word)
        vec.push_back(word);

    auto iter = partition(vec.begin(), vec.end(), longerThanFive);

    for (auto i = vec.begin(); i != iter; ++i){
        cout << *i << " ";
    }

    return 0;
}
