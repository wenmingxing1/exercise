#include<iostream>

using namespace std;

int main()
{
    int i = 0;
    auto f = [&i] () ->bool {
        if (i == 0) return true;
        else {
            while (i != 0) --i;
            return false;
            }
        };

    cout << f() << endl;
    cout << i << endl;
}
