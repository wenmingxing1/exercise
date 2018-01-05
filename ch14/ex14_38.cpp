#include<iostream>
#include<string>
#include<vector>
#include<fstream>

using namespace std;

class String_Size
{
public:
    String_Size(int i, int j) : lower(i), upper(j) {}

    bool operator() (const string& str)
    {
        return str.size() >= lower && str.size() <= upper;
    }

private:
    size_t lower;
    size_t upper;
};

int main()
{
    ifstream ifs("./data/string.txt");
    int count1_3 = 0;   //低于6的个数
    int count4 = 0;    //超过6的个数
    string str;
    String_Size string_size(1,3);

    while (ifs >> str){
        if (string_size(str))
            ++count1_3;
        else
            ++count4;
    }

    cout << count1_3 << endl;
    cout << count4 << endl;
}
