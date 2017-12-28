#include<iostream>

using namespace std;

int main()
{
    int i = 42;
    auto f = [i] (int b) {return i+b;};

    cout << f(4) << endl;

    return 0;
}
