#ifndef EX15_15_DISC_QUOTE_H_INCLUDED
#define EX15_15_DISC_QUOTE_H_INCLUDED

#include "ex15_03_Quote.h"

//�������
class Disc_quote : public Quote
{
public:
    Disc_quote() = default;
    Disc_quote(const string& book, double p, size_t qty, double dis)
        : Quote(book, p), min_qty(qty), discount(dis) { }

    virtual double net_price(size_t n) const = 0;   //���麯��

protected:  //��Ϊ��Ҫ�����������
    size_t min_qty = 0;
    double discount = 0.0;
};

#endif // EX15_15_DISC_QUOTE_H_INCLUDED
