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
        //��str��i��ʼ��pair��Ȼ��push_back��vector��
        vec.push_back(pair<string, int>(str, i));

        //������ʼ������
        //vec.push_back(make_pair(str, i));     //����make_pair
        //vec.push_back({str, i});
    }

    for (const auto &p : vec) {
        cout << p.first << ":" << p.second << endl;
    }

    return 0;
}
