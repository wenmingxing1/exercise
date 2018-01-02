#include<iostream>
#include<vector>

using namespace std;

struct X
{
    X() {cout << "X():默认构造函数" << endl;}
    X(const X&) {cout << "X(const X&): 拷贝构造函数" << endl;}
    X& operator=(const X&) {cout << "operator= : 拷贝赋值运算符" << endl; return *this;}
    ~X() {cout << "~X():析构函数" << endl;}
};

int main()
{
    X x1;
    X x2 = x1;
    X x3;
    x3 = x1;
    vector<X> vec;
    X* px = new X;

    delete px;

    return 0;
}
