#include<iostream>
#include<string>
#include<vector>
#include<deque>

using namespace std;

int main()
{
    deque<string> de;
    string word;
    while (cin >> word)
        de.push_back(word);

    deque<string>::const_iterator iter = de.cbegin();   //const_iterator∂‘”¶cbegiin
    while (iter != de.cend()) {
        cout << *iter << " ";
        ++iter;
    }

    return 0;
}
