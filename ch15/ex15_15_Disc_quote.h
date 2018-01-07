#ifndef EX15_15_DISC_QUOTE_H_INCLUDED
#define EX15_15_DISC_QUOTE_H_INCLUDED

#include "ex15_03_Quote.h"

//抽象基类
class Disc_quote : public Quote
{
public:
    Disc_quote() = default;
    Disc_quote(const string& book, double p, size_t qty, double dis)
        : Quote(book, p), min_qty(qty), discount(dis) { }

    virtual double net_price(size_t n) const = 0;   //纯虚函数

protected:  //因为需要被派生类访问
    size_t min_qty = 0;
    double discount = 0.0;
};

#endif // EX15_15_DISC_QUOTE_H_INCLUDED
