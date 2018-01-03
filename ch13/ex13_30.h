#ifndef EX13_30_H_INCLUDED
#define EX13_30_H_INCLUDED

#include<iostream>
#include<string>

using namespace std;

class HasPtr
{
public:
    friend void swap(HasPtr& hp1, HasPtr& hp2);
    HasPtr(const string& s = string()) : ps(new string(s)), i(0) { }
    HasPtr(const HasPtr& hp) : ps(new string(*hp.ps)), i(hp.i) { }

    HasPtr& operator=(const HasPtr& hp)
    {
        auto new_p = new string(*hp.ps);
        delete ps;
        ps = new_p;
        i = hp.i;
        return *this;
    }
    ~HasPtr() {delete ps;}

private:
    string *ps;
    int i;
};

void swap(HasPtr& hp1, HasPtr& hp2)
{
    swap(hp1.ps, hp2.ps);
    swap(hp1.i, hp2.i
    cout << "call swap!" << endl;
}

#endif // EX13_30_H_INCLUDED
