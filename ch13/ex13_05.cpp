#include<iostream>
#include<string>

using namespace std;

class HasPtr
{
public:
    HasPtr(const string &s = string()) : ps (new string(s)), i(0) {}

    //拷贝构造函数
    HasPtr(const HasPtr& Has) : ps(new string(*Has.ps)), i(0) {}

    //拷贝赋值运算符
    HasPtr& operator=(const HasPtr& Has) {
        ps = new string(*Has.ps);
        i = Has.i
        return *this;   //记住返回值
    }

    ~HasPtr() {delete ps;}  //析构函数,因为合成的构造函数不会delete一个指针数据成员，所以需要自己定义析构函数
private:
    string *ps;
    int i;
};



