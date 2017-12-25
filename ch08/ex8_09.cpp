#include<iostream>
#include<sstream>
#include<string>
using namespace std;

istream& func(istream& is) {
    string buf;
    while (is >> buf)
        cout << buf << endl;

    is.clear();
    return is;
}

int main()
{
    istringstream iss("hello");
    func(iss);

    return 0;
}
