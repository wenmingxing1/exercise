#ifndef EX15_03_QUOTE_H_INCLUDED
#define EX15_03_QUOTE_H_INCLUDED

#include<string>
#include<iostream>

using namespace std;

class Quote
{
public:
    Quote() = default;
    Quote(const string& book, double p) : bookNo(book), price(p) { }

    string isbn() const {return bookNo;}

    //返回给定数量书籍的销售总额，派生类负责制定不同的折扣计算方法
    virtual double net_price(size_t n) const
    {
        return n*price;
    }

    //ex15_11:增加debug虚函数
    virtual void debug() const
    {
        cout << isbn() << " " << price << endl;
    }

    virtual ~Quote() = default; //对析构函数进行动态绑定

private:
    string bookNo;

protected:
    double price = 0.0;
};

//输出销售额的函数，根据传入item的不同调用不同的net_price函数，完成动态绑定
double print_total(ostream& os, const Quote& item, size_t n)
{
    double ret = item.net_price(n);
    os << item.isbn() << " sold " << n << " books, and total money is: " << ret << endl;
    return ret;
}

#endif // EX15_03_QUOTE_H_INCLUDED
