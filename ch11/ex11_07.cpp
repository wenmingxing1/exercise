#include<iostream>
#include<vector>
#include<map>

using namespace std;

int main()
{
    map<string, vector<string>> Famliy
    {
        { "li", { "gang", "shuo", "jianmin" } },
        { "guo", { "june" } }
    };

    for (auto famliy : Famliy) {
        cout << famliy.first << ":" << endl;
        for (auto name : famliy.second)
            cout << name << ";";
        cout << endl;
    }


    return 0;

}
