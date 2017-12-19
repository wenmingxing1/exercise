#ifndef PERSON_H_INCLUDED
#define PERSON_H_INCLUDED

#include<string>
#include<iostream>
using namespace std;

class Person
{
public:
    const string& getname() const {return name;}
    const string& getaddress() const {return address;}

//private:
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
