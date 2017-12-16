#include<iostream>
#include<stdexcept>    //异常头文件
using namespace std;

int main()
{
    int i, j;
    while (cin >> i >> j)
    {
        try
        {
            if (j == 0) throw runtime_error("divisor is 0!");
            cout << (double)(i)/j << endl;
        }
        catch (runtime_error err)
        {
            cout << err.what() << endl;     //输出异常信息
            cout << "please input j:" << endl;
            cin >> j;
            cout << (double)(i)/j << endl;
        }
    }
}
