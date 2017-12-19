#ifndef SALES_DATA_H_INCLUDED
#define SALES_DATA_H_INCLUDED

#include<string>
using namespace std;

//定义Sales_data类
class Sales_data
{
public:
    string isbn() const {return bookNo;}
    Sales_data& combine(const Sales_data&);
    double avg_price() const;

    string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
};

//类外定义成员函数
Sales_data& Sales_data::combine(const Sales_data &rhs) {    //模仿+=运算符，所以返回为引用类型，是一个左值
    units_sold += rhs.units_sold;
    revenue += rhs.revenue;
    return *this;   //返回对象
}

//平均价格
double Sales_data::avg_price() const {
    if (units_sold)
        return revenue/units_sold;
    else
        return 0;
}

//类外函数声明
istream& read(istream& is, Sales_data& item)   //读入函数
{
    double price;
    is >> item.bookNo >> item.units_sold >> price;
    item.revenue = item.units_sold * price;
    return is;
}
ostream& print(ostream& os, Sales_data& item)  //打印函数
{
    os << item.isbn() << " " << item.units_sold << " " << item.revenue << " " << item.avg_price();
    return os;
}
//加法函数
Sales_data add(const Sales_data &item1, const Sales_data &item2) {
    Sales_data newBook;
    if (item1.bookNo == item2.bookNo){
        newBook.units_sold = item1.units_sold + item2.units_sold;
        newBook.revenue = item1.revenue + item2.revenue;
    }
    return newBook;
}

#endif // SALES_DATA_H_INCLUDED
