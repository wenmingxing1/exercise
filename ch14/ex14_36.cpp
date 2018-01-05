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
        getline(is, str);
        if (is)
            return str;
        else
            return string();
    }
private:
    istream& is;
};

int main()
{
    PrintString test;
    vector<string> vec;

    //输入不为空的时候压入vec
    for (string temp; !(temp = test()).empty();)
        vec.push_back(temp);

    for (auto str : vec)
        cout << str << " ";

    return 0;
}
