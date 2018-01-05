#include "ex14_02.h"

istream& operator>>(istream& is, Sales_data& item)
{
    double price = 0.0;
    is >> item.bookNo >> item.units_sold >> price;

    if (is)     //需要判断输入是否正常
        item.revenue = item.units_sold * price;
    else    //若不正常则返回一个空对象
        item = Sales_data();

    return is;
}

//以>>完成构造函数
Sales_data::Sales_data(istream& is)
{
    is >> *this;
}

ostream& operator<<(ostream& os, const Sales_data& item)
{
    os << item.isbn() << " " << item.units_sold << " "
       << item.revenue;

    return os;
}

Sales_data& Sales_data::operator+=(const Sales_data& item)
{
    units_sold += item.units_sold;
    revenue += item.revenue;
    return *this;   //返回值很重要
}

//以成员函数+=完成非成员函数+
Sales_data operator+(const Sales_data& item1, const Sales_data& item2)
{
    Sales_data sum = item1;
    sum += item2;
    return sum;
}
