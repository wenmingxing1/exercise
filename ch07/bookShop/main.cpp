#include<iostream>
#include "Sales_data.h"
//using namespace std;

int main()
{
    Sales_data total;
    //输入total信息
    cout << "Please input the total's isbn, numbers, and price:" << endl;
    if (read(cin, total)) {
        Sales_data trans;
        //输入新信息
        while (read(cin, trans)) {
            if (total.isbn() == trans.isbn()) {     //判断是否与之前信息相同
                total.combine(trans);   //更新信息
            }
            //若不同
            else {
                print(cout, total) << endl;     //输出旧信息
                total = trans;      //处理下一信息
            }
        }
        print(cout, total) << endl; //输出最后一条
    }
    //没有信息输入
    else{
        cerr << "No data!" << endl;
    }
}
