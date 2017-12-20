#ifndef PERSON_H_INCLUDED
#define PERSON_H_INCLUDED

#include<string>
#include<iostream>
using namespace std;

class Person;   //��readǰ�����࣬��Ϊread��������Ҫ�õ�Person
istream& read(istream &is, Person &person); //�ڹ��캯��������read��������Ϊ���������캯����Ҫ����read����

class Person
{
    //������Ԫ����ʹ�÷����Ա�������Է���private����
    friend istream& read(istream &is, Person &person);
    friend ostream& print(ostream &os, const Person &person);
public:
    //���ӹ��캯��
    Person() = default; //Ĭ�Ϲ��캯��
    Person(const string sname, const string saddress) : name(sname), address(saddress) {}
    Person(istream &is) { read(is, *this); }

    const string& getname() const {return name;}
    const string& getaddress() const {return address;}

private:
    string name;
    string address;
};

istream& read(istream& is, Person& person){
    is >> person.name >> person.address;
    //if (!is) person = Person();  //���û�����룬�����Ĭ�Ϲ��캯��
    return is;
}

ostream& print(ostream& os, const Person& person) {
    os << person.name << " " << person.address;
    return os;
}

#endif // PERSON_H_INCLUDED
