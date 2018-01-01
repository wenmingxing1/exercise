#include<iostream>
#include<string>
#include<cstring>

using namespace std;

int main()
{
    const char *ch1 = "hello ";
    const char *ch2 = "world";

    unsigned len = strlen(ch1) + strlen(ch2) + 1;   //º¬ÓÐÒ»¸ö¿Õ×Ö·û

    char * res = new char[len];

    strcat(res, ch1);
    strcat(res, ch2);
    cout << res << endl;

    delete [] res;

    string str1{"hello "};
    string str2{"world"};

    string res2 = str1+str2;

    cout << res2 << endl;

    return 0;
}
