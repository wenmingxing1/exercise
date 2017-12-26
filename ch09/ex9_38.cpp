#include<iostream>
#include<vector>
#include<string>
using namespace std;

//≤‚ ‘vector¿©»›
void test_vector() {
    vector<string> vec;
    string str;
    while (cin >> str) {
        vec.push_back(str);
        cout << vec.capacity() << endl;
    }
}

//≤‚ ‘string¿©»›
void test_string() {
    string str;
    char ch;
    while (cin >> ch) {
        str.push_back(ch);
        cout << str.capacity() << endl;
    }
}
int main()
{
    //test_vector();

    test_string();


    return 0;
}
