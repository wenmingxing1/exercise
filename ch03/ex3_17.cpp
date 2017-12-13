#include<iostream>
#include<vector>
#include<string>
#include<cctype>
using namespace std;

int main()
{
    vector<string> vec;
    string str;
    int count = 3;  //控制输入个数
    while (cin >> str && count != -1){
        vec.push_back(str);
        --count;
    }

    for (auto &str : vec){
            for (auto &ch : str){
                ch = toupper(ch);
            }
    }

    for (int i = 0; i < vec.size(); ++i){
        cout << vec[i] << endl;
    }

    return 0;
}
