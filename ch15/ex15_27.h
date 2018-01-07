#ifndef EX15_27_H_INCLUDED
#define EX15_27_H_INCLUDED

#include "ex15_03_Quote.h"

class Bulk_quote
{
public:
    //�̳л��๹�캯��
    using Quote::Quote;
    virtual double net_price(size_t cnt) const override
    {
        if (cnt >= min_qty) return cnt*price*(1-discount);
        else return cnt*price;
    }
};

#endif // EX15_27_H_INCLUDED
