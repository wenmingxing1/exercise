#ifndef EX13_31_H_INCLUDED
#define EX13_31_H_INCLUDED

#include<iostream>
#include<string>

using namespace std;

class HasPtr
{
public:
    friend void swap(HasPtr& hp1, HasPtr& hp2);

    friend bool operator<(const HasPtr& hp1, const HasPtr& hp2);

    HasPtr(const string& s = string()) : ps(new string(s)), i(0) { }
    HasPtr(const HasPtr& hp) : ps(new string(*hp.ps)), i(0) { }

    //利用swap定义拷贝赋值运算符，可以直接处理自赋值问题
    HasPtr& operator=(HasPtr& hp)
    {
        this->swap(hp);
        return *this;
    }

    void swap(HasPtr& hp)
    {
        swap(ps, hp.ps);
        swap(i, hp.i);
    }

    ~HasPtr() {delete ps;}

private:
    string *ps;
    int i;
};

void swap(HasPtr& hp1, HasPtr& hp2)
{
    hp1.swap(hp2);
}

bool operator<(const HasPtr& hp1, const HasPtr& hp2)
{
    return *hp1.ps < *hp2.ps;
}

#endif // EX13_31_H_INCLUDED
