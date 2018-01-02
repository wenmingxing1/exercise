#ifndef EX13_27_H_INCLUDED
#define EX13_27_H_INCLUDED

#include<iostream>
#include<string>

using namespace std;

//引用计数，类指针
class HasPtr
{
public:
    //构造函数分配新的string，和新的引用计数，将计数器置为1
    HasPtr(const string& s = string()) : ps(new string(s)), i(0), use(new size_t(1)){ }
    //拷贝构造函数会对拷贝对象增加引用计数器，共用ps
    HasPtr(const HasPtr& p) : ps(p.ps), i(p.i), use(p.use) {++*use;}
    //拷贝赋值运算符
    HasPtr& operator=(const HasPtr&);
    //析构函数
    ~HasPtr();

private:
    string *ps;
    int i;
    size_t *use;    //用来记录有多少个对象共享*ps的成员
};

HasPtr::~HasPtr()
{
    if (--*use) {   //如果引用计数器为0，则析构
        delete ps;
        delete use;
    }
}

HasPtr& HasPtr::operator=(const HasPtr& rhs) {
    ++*rhs.use; //递增右侧计数器
    if (--*use) {
        delete ps;
        delete use;
    }

    ps = rhs.ps;    //共享对象，不再重新分配内存
    i = rhs.i;
    use = rhs.use;

    return *this;   //记住拷贝赋值运算符返回对象
}

#endif // EX13_27_H_INCLUDED
