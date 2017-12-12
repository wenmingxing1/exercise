#include<iostream>
#include<string>
using namespace std;

struct Sales_data
{
    string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
};

int main()
{
    Sales_data data1, data2;
    double price = 0;
    cout << "please input the bookNo£¬ units_sold£¬ price£º" << endl;
    cin >> data1.bookNo >> data1.units_sold >> data1.revenue;

    cout << data1.bookNo << " " << data1.units_sold << " " << data1.revenue << endl;
}
