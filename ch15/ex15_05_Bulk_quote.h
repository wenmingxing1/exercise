#ifndef EX15_05_BULK_QUOTE_H_INCLUDED
#define EX15_05_BULK_QUOTE_H_INCLUDED

#include "ex15_03_Quote.h"

class Bulk_quote : public Quote
{
public:
    Bulk_quote() = default;
    Bulk_quote(const string& book, double p, size_t qty, double dis)
        : Quote(book, p), min_qty(qty), discount(dis) { }

    //override�������ۿ۲���
    virtual double net_price(size_t n) const override
    {
        if (n >= min_qty)
            return n*(1-discount)*price;
        else
            return n*price;
    }

    //ex15_11:debug�麯��
    void virtual debug() const override
    {
        Quote::debug();     //�ȵ��û��ಿ��
        cout << min_qty << " " << discount << endl;
        //cout << isbn() << " " << price << " " << min_qty << " " << discount << endl;
    }

private:
    size_t min_qty = 0;     //��ʹ���ۿ۵���С��������
    double discount = 0.0;  //�ۿ۶�
};

#endif // EX15_05_BULK_QUOTE_H_INCLUDED
