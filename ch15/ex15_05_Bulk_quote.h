#ifndef EX15_05_BULK_QUOTE_H_INCLUDED
#define EX15_05_BULK_QUOTE_H_INCLUDED

#include "ex15_03_Quote.h"

class Bulk_quote : public Quote
{
public:
    Bulk_quote() = default;
    Bulk_quote(const string& book, double p, size_t qty, double dis)
        : Quote(book, p), min_qty(qty), discount(dis) { }

    //override派生类折扣策略
    virtual double net_price(size_t n) const override
    {
        if (n >= min_qty)
            return n*(1-discount)*price;
        else
            return n*price;
    }

private:
    size_t min_qty = 0;     //可使用折扣的最小购买数量
    double discount = 0.0;  //折扣额
};

#endif // EX15_05_BULK_QUOTE_H_INCLUDED
