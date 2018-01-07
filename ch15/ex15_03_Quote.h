#ifndef EX15_03_QUOTE_H_INCLUDED
#define EX15_03_QUOTE_H_INCLUDED

#include<string>
#include<iostream>

using namespace std;

class Quote
{
public:
    Quote()
    {
        cout << "Quote Constructor" << endl;
    }
    //接受两个参数的构造函数
    Quote(const string& book, double p) : bookNo(book), price(p)
    {
        cout << "Quote Constructor taking two parameters" << endl;
    }
    //拷贝构造函数
    Quote(const Quote& item) : bookNo(item.bookNo), price(item.price)
    {
        cout << "Quote Copy Constructor" << endl;
    }
    //拷贝赋值运算符
    Quote& operator=(const Quote& item)
    {
        bookNo = item.bookNo;
        price = item.price;
        cout << "Quote Copy assignment operator" << endl;

        return *this;
    }

    //移动构造函数
    Quote(Quote&& item) noexcept : bookNo(std::move(item.bookNo)), price(std::move(item.price))
    {
        cout << "Quote Move Constructor" << endl;
    }

    //移动赋值运算符
    Quote& operator=(Quote&& item) noexcept
    {
        bookNo = std::move(item.bookNo);
        price = std::move(item.price);
        cout << "Quote Move assignment operator" << endl;

        return *this;
    }

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

    //对析构函数进行动态绑定
    virtual ~Quote()
    {
        cout << "Quote Destructor" << endl;
    }

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
