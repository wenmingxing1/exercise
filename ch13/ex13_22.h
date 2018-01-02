#ifndef EX13_22_H_INCLUDED
#define EX13_22_H_INCLUDED

#include<iostream>
#include<string>

using namespace std;

//类值，每个对象都有自己的状态
class HasPtr
{
public:
    HasPtr(const string& s = string()) : ps(new string(s)), i(0) { }
    HasPtr(const HasPtr& hp) : ps(new string(*hp.ps)), i(hp.i) { }

    HasPtr& operator=(const HasPtr&);
    ~HasPtr() {delete ps;}

private:
    string *ps;
    int i;
};

HasPtr& HasPtr::operator=(const HasPtr& rhs)
{
    auto newp = new string(*rhs.ps);   //拷贝底层string

    delete ps;  //释放旧内存,很关键！！！

    ps = newp;
    i = rhs.i;

    return *this;
}

#endif // EX13_22_H_INCLUDED
