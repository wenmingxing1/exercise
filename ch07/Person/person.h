#ifndef PERSON_H_INCLUDED
#define PERSON_H_INCLUDED

#include<string>
#include<iostream>
using namespace std;

class Person;   //在read前声明类，因为read函数中需要用到Person
istream& read(istream &is, Person &person); //在构造函数中声明read函数，因为第三个构造函数需要调用read函数

class Person
{
    //增加友元函数使得非类成员函数可以访问private数据
    friend istream& read(istream &is, Person &person);
    friend ostream& print(ostream &os, const Person &person);
public:
    //增加构造函数
    Person() = default; //默认构造函数
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
    //if (!is) person = Person();  //如果没有输入，则调用默认构造函数
    return is;
}

ostream& print(ostream& os, const Person& person) {
    os << person.name << " " << person.address;
    return os;
}

#endif // PERSON_H_INCLUDED
