#include<iostream>
#include<string>
using namespace std;

string make_plural(string::size_type sz, string& str1, char ch = 's'){
    if (sz > 1){
        return str1+ch;
    }
    else    return str1;
}

int main()
{
    string str = "success";
    int sz1 = 1;
    int sz2 = 5;
    cout << make_plural(sz1, str) << endl;
    cout << make_plural(sz2, str) << endl;

    return 0;
}
