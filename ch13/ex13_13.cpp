#include<iostream>
#include<vector>

using namespace std;

struct X
{
    X() {cout << "X():Ĭ�Ϲ��캯��" << endl;}
    X(const X&) {cout << "X(const X&): �������캯��" << endl;}
    X& operator=(const X&) {cout << "operator= : ������ֵ�����" << endl; return *this;}
    ~X() {cout << "~X():��������" << endl;}
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
