#ifndef EX14_02_H_INCLUDED
#define EX14_02_H_INCLUDED

#include<string>
#include<iostream>

using namespace std;

class Sales_data
{
    friend istream& operator>>(istream&, Sales_data&);  //input
    friend ostream& operator<<(ostream&, const Sales_data&);  //output
    friend Sales_data operator+(const Sales_data&, const Sales_data&);  //add
public:
    Sales_data() = default;
    Sales_data(const string& s) : bookNo(s) {}
    Sales_data(const string& s, unsigned i, double p) : bookNo(s), units_sold(i), revenue(i*p) {}
    Sales_data(const Sales_data& item)
    {
        *this = item;
    }     //拷贝构造函数
    Sales_data& operator=(const Sales_data& item)
    {
        bookNo = item.bookNo;
        units_sold = item.units_sold;
        revenue = item.revenue;
        return *this;
    }
    //一个接受string的赋值运算符
    Sales_data& operator=(const string& str)
    {
        bookNo = str;
        units_sold = 0;
        revenue = 0.0;
    }
    Sales_data(istream& is);

    Sales_data& operator+=(const Sales_data&);

    string isbn() const {return bookNo;}

private:
    string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
};

istream& operator>>(istream&, Sales_data&);
ostream& operator<<(ostream&, const Sales_data&);
Sales_data operator+(const Sales_data&, const Sales_data&);

#endif // EX14_02_H_INCLUDED
