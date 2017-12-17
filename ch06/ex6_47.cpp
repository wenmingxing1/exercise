//#define NDEBUG
#include<iostream>
#include<vector>
using namespace std;

void PrintVector(vector<int>& vec){
    #ifndef NDEBUG
        cerr << "the size is :" << vec.size() << endl;
    #endif

    if (!vec.empty()){
        int temp = vec.back();
        cout << "pop number:" << temp << endl;
        vec.pop_back();
        PrintVector(vec);
    }
}

int main()
{
    vector<int> vec{1,2,3,4,5,6};
    PrintVector(vec);

    return 0;
}
