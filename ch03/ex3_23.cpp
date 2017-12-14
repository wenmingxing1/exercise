#include<iostream>
#include<vector>
using namespace std;

void Print(vector<int> vec){
    int num = vec.size();
    for (int i = 0; i < num; ++i){
        cout << vec[i] << " ";
    }
}
int main()
{
    vector<int> vec{1,2,3,4,5,6,7,8,9,0};
    vector<int>::iterator iter = vec.begin();
    for (; iter != vec.end(); ++iter){
        *iter *= 2;
    }

    Print(vec);
}
