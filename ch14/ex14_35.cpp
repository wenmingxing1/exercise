#include<iostream>
#include<string>
#include<vector>

using namespace std;

class PrintString
{
public:
    PrintString(istream& i = cin) : is(i) {}

    string operator() () const
    {
        string str;
        //getline(is, str);
        is >> str;
        if (is)
            return str;
        else
            return string();    //¿ÕµÄstring
    }

private:
    istream& is;
};

int main()
{
    PrintString test;
    cout << test() << endl;

    return 0;
}
