#include<iostream>
#include<string>
using namespace std;

void oldToNew(string& s, const string& oldVal, const string& newVal) {
    for (int i = 0; i != s.size(); ++i) {
        if (s.substr(i, oldVal.size()) == oldVal) {
            s.replace(i, oldVal.size(), newVal);
            i += newVal.size() - 1;
        }
    }
}

int main()
{
    string str{"To drive straight thru is a foolish, tho courageous act."};
    oldToNew(str, "tho", "though");

    cout << str << endl;

    return 0;
}
