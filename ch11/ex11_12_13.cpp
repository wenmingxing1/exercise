#include<iostream>
#include<string>
#include<vector>
#include<utility>
#include<fstream>

using namespace std;

int main()
{
    vector<pair<string, int>> vec;
    string str;
    int i;
    ifstream ifs("./data/pair.txt");
    while (ifs >> str >> i) {
        //以str和i初始化pair，然后push_back到vector中
        vec.push_back(pair<string, int>(str, i));

        //其他初始化方法
        //vec.push_back(make_pair(str, i));     //利用make_pair
        //vec.push_back({str, i});
    }

    for (const auto &p : vec) {
        cout << p.first << ":" << p.second << endl;
    }

    return 0;
}
