#include<iostream>
#include<vector>

using namespace std;

class Nodefault
{
public:
    Nodefault(int i) : abc(i) {}

private:
    int abc;
};

class C
{
public:
    C() : nodefault(0) {}   //C的默认构造函数

private:
    Nodefault nodefault;
};

int main()
{
    C c;
    //vector<Nodefault> vec(10);  //error，因为Nodefault没有默认构造函数
    vector<C> vec(10);  //没问题

    return 0;
}
