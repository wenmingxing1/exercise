#ifndef EX15_15_DISC_BULK_QUOTE_H_INCLUDED
#define EX15_15_DISC_BULK_QUOTE_H_INCLUDED

#include "ex15_15_Disc_quote.h"

//继承自抽象基类的派生类
class Disc_Bulk_quote : public Disc_quote
{
public:
    Disc_Bulk_quote() = default;
    Disc_Bulk_quote(const string& book, double p, size_t qty, double dis)
        : Disc_quote(book, p, qty, dis) { }

    virtual double net_price(size_t n) const override
    {
        if (n >= min_qty)
            return n*price*(1-discount);
        else
            return n*price;
    }

private:

};

#endif // EX15_15_DISC_BULK_QUOTE_H_INCLUDED
