#ifndef EX13_22_H_INCLUDED
#define EX13_22_H_INCLUDED

#include<iostream>
#include<string>

using namespace std;

//��ֵ��ÿ���������Լ���״̬
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
    auto newp = new string(*rhs.ps);   //�����ײ�string

    delete ps;  //�ͷž��ڴ�,�ܹؼ�������

    ps = newp;
    i = rhs.i;

    return *this;
}

#endif // EX13_22_H_INCLUDED
