#ifndef EX15_05_BULK_QUOTE_H_INCLUDED
#define EX15_05_BULK_QUOTE_H_INCLUDED

#include "ex15_03_Quote.h"

class Bulk_quote : public Quote
{
public:
    Bulk_quote()
    {
        cout << "Bulk_quote Constructor" << endl;
    }

    Bulk_quote(const string& book, double p, size_t qty, double dis)
        : Quote(book, p), min_qty(qty), discount(dis)
    {
        cout << "Bulk_quote Constructor taking four parameters" << endl;
    }

    //����ʽ���û��࿽�����캯�������������Ŀ������캯��
    Bulk_quote(const Bulk_quote& item) : Quote(item), min_qty(item.min_qty), discount(item.discount)
    {
        cout << "Bulk_quote Copy Constructor" << endl;
    }

    //������ֵ�����
    Bulk_quote& operator=(const Bulk_quote& item)
    {
        Quote::operator=(item); //����ʽ���û��࿽����ֵ�����
        min_qty = item.min_qty;
        discount = item.discount;
        cout << "Bulk_quote Copy assignment operator" << endl;
        return *this;
    }

    //�ȵ��û����ƶ����캯������������ƶ����캯��
    Bulk_quote(Bulk_quote&& item) noexcept : Quote(item), min_qty(std::move(item.min_qty)),
                                                          discount(std::move(item.discount))
    {
        cout << "Bulk_quote Move Constructor" << endl;
    }

    Bulk_quote& operator=(Bulk_quote&& item) noexcept
    {
        Quote::operator=(item); //����ʽ���û����ƶ���ֵ�����
        min_qty = std::move(item.min_qty);
        discount = std::move(item.discount);

        cout << "Bulk_quote Move assignment operator" << endl;
        return *this;
    }

    virtual ~Bulk_quote()
    {
        cout << "Bulk_quote Destructor" << endl;
    }
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
