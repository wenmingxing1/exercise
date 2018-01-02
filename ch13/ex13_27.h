#ifndef EX13_27_H_INCLUDED
#define EX13_27_H_INCLUDED

#include<iostream>
#include<string>

using namespace std;

//���ü�������ָ��
class HasPtr
{
public:
    //���캯�������µ�string�����µ����ü���������������Ϊ1
    HasPtr(const string& s = string()) : ps(new string(s)), i(0), use(new size_t(1)){ }
    //�������캯����Կ��������������ü�����������ps
    HasPtr(const HasPtr& p) : ps(p.ps), i(p.i), use(p.use) {++*use;}
    //������ֵ�����
    HasPtr& operator=(const HasPtr&);
    //��������
    ~HasPtr();

private:
    string *ps;
    int i;
    size_t *use;    //������¼�ж��ٸ�������*ps�ĳ�Ա
};

HasPtr::~HasPtr()
{
    if (--*use) {   //������ü�����Ϊ0��������
        delete ps;
        delete use;
    }
}

HasPtr& HasPtr::operator=(const HasPtr& rhs) {
    ++*rhs.use; //�����Ҳ������
    if (--*use) {
        delete ps;
        delete use;
    }

    ps = rhs.ps;    //������󣬲������·����ڴ�
    i = rhs.i;
    use = rhs.use;

    return *this;   //��ס������ֵ��������ض���
}

#endif // EX13_27_H_INCLUDED
