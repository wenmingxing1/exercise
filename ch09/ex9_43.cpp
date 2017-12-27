#include<iostream>
#include<string>
using namespace std;

void oldToNew(string& s, const string& oldVal, const string& newVal) {
    auto iter = s.begin();
    while (iter != s.end()-oldVal.size()) {
        if (string{iter, iter + oldVal.size()} == oldVal) {     //�����Χ�����
            iter = s.erase(iter, iter + oldVal.size());
            iter = s.insert(iter, newVal.cbegin(), newVal.cend());
            std::advance(iter, newVal.size());  //��iter��ǰ�ƶ�newVal.size(),������һ��
        }
        else
            ++iter;
    }
}

int main()
{
    string str{"To drive straight thru is a foolish, tho courageous act."};
    oldToNew(str, "tho", "though");

    cout << str << endl;

    return 0;
}
