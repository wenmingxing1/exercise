#include<iostream>
#include<string>
#include<vector>
using namespace std;

void theFirst()
{
    string str{"ab2c3d7R4E6"};
    string numbers{"0123456789"};
    string letter{"abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"};
    vector<int> res;

    int pos = 0;
    while (pos < str.size()) {
        pos = str.find_first_of(numbers, pos);
        cout << pos << " ";
        ++pos;
    }


    cout << endl;
    pos = 0;
    //´æÔÚÎÊÌâ
    while (pos < str.size()) {
        pos = str.find_first_not_of(numbers, pos);
        cout << pos << " ";
        ++pos;
    }

}

int main()
{
    theFirst();

    return 0;
}
