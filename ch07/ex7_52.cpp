#include<iostream>
#include<string>

using namespace std;

struct Sales_data
{
    string bookNo;
    unsigned units_sold;
    double revenue;
};

int main()
{
    Sales_data test{"niubi", 1, 2.0};
}
