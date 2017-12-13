#include<iostream>
#include<string>
using namespace std;

void test1()
{
    string str("abcde");
    for (auto &ch : str){   //要改变ch的值需要定义为引用类型
        ch = 'X';
    }

    cout << str << endl;
}

void test2()
{
    string str("abcde");
    int i = 0;
    while (i < str.size()){
        str[i] = 'X';
        ++i;
    }

    cout << str << endl;
}

int main()
{
    test2();

    return 0;
}
