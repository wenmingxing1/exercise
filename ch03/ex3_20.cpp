#include<iostream>
#include<vector>
using namespace std;

void Print(vector<int> vec){
    for (int i = 0; i < vec.size(); ++i)
        cout << vec[i] << " ";
}

int main()
{
    vector<int> vec;
    int i;
    int count = 5;
    while (cin >> i && count > 0){
        vec.push_back(i);
        --count;
    }

    Print(vec);
    cout << endl;

    int begin = 0;
    int end = vec.size()-1;

    while (begin != end){
        cout << "sum:" << vec[begin] + vec[end] << endl;
        ++begin;
        --end;
    }



    return 0;

}

