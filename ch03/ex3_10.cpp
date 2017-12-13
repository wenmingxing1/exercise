#include<iostream>
#include<string>
#include<cctype>
using namespace std;

void del(string &str){
    for (int i = 0; i < str.size(); ++i){
        if (!ispunct(str[i]))
            cout << str[i];
    }
}
int main()
{
    string str("I love you,and do you love me?");
    cout << str << endl;
    del(str);

    return 0;
}
