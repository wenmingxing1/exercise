#include<iostream>
#include<string>

using namespace std;

class HasPtr
{
public:
    HasPtr(const string &s = string()) : ps (new string(s)), i(0) {}

    //�������캯��
    HasPtr(const HasPtr& Has) : ps(new string(*Has.ps)), i(0) {}

    //������ֵ�����
    HasPtr& operator=(const HasPtr& Has) {
        ps = new string(*Has.ps);
        i = Has.i
        return *this;   //��ס����ֵ
    }

    ~HasPtr() {delete ps;}  //��������,��Ϊ�ϳɵĹ��캯������deleteһ��ָ�����ݳ�Ա��������Ҫ�Լ�������������
private:
    string *ps;
    int i;
};



