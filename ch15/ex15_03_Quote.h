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

    //���ظ��������鼮�������ܶ�����ฺ���ƶ���ͬ���ۿۼ��㷽��
    virtual double net_price(size_t n) const
    {
        return n*price;
    }

    //ex15_11:����debug�麯��
    virtual void debug() const
    {
        cout << isbn() << " " << price << endl;
    }

    virtual ~Quote() = default; //�������������ж�̬��

private:
    string bookNo;

protected:
    double price = 0.0;
};

//������۶�ĺ��������ݴ���item�Ĳ�ͬ���ò�ͬ��net_price��������ɶ�̬��
double print_total(ostream& os, const Quote& item, size_t n)
{
    double ret = item.net_price(n);
    os << item.isbn() << " sold " << n << " books, and total money is: " << ret << endl;
    return ret;
}

#endif // EX15_03_QUOTE_H_INCLUDED
