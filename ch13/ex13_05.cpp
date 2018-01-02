#include<iostream>
#include<string>

using namespace std;

class HasPtr
{
public:
    HasPtr(const string &s = string()) : ps (new string(s)), i(0) {}

    //¿½±´¹¹Ôìº¯Êý
    HasPtr(const HasPtr& Has) : ps(new string(*Has.ps)), i(0) {}
private:
    string *ps;
    int i;
};



