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
    C() : nodefault(0) {}   //C��Ĭ�Ϲ��캯��

private:
    Nodefault nodefault;
};

int main()
{
    C c;
    //vector<Nodefault> vec(10);  //error����ΪNodefaultû��Ĭ�Ϲ��캯��
    vector<C> vec(10);  //û����

    return 0;
}
