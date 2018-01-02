#include<iostream>
#include<string>

using namespace std;

class Employee
{
public:
    //static int num = 1;
    Employee()
    {
        static int num = 1;
        ID = num++;
    }
    Employee(const string& s) : name(s)
    {
        static int num = 1;
        ID = num++;
    }

    string name;
    int ID;
};


int main()
{
    Employee em1;
    Employee em2("ligang");
    Employee em3;

    cout << em3.ID << endl; //»áÊä³ö2

    cout << em1.ID << em1.name << endl;
    cout << em2.ID << " " << em2.name << endl;

    return 0;
}
