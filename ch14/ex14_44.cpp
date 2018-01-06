#include<iostream>
#include<map>
#include<string>
#include<functional>
#include<algorithm>

using namespace std;

int add(int i, int j) {return i+j;} //普通函数形式
auto sub = [](int i, int j){return i - j;};  //lambda表达式形式
struct mul
{
    int operator() (int i, int j) {return i*j;}     //函数对象类形式
};

//divides<int>()    //标准库函数对象形式

int main()
{
    map<string, function<int(int, int)>> Caculate;
    Caculate.insert({"+", add});    //利用函数指针传入
    Caculate.insert({"-",sub});
    Caculate.insert({"*", mul()});  //函数对象类传入
    Caculate.insert({"/", divides<int>()}); //标准库函数对象

    cout << "Please input :(如：10 + 5)" << endl;
    int firstNumber;
    int secondNumber;
    string str;

    while (cin >> firstNumber >> str >> secondNumber)
        cout << Caculate[str](firstNumber, secondNumber) << endl;


    return 0;
}
