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
    //�������������Ĺ��캯��
    Quote(const string& book, double p) : bookNo(book), price(p)
    {
        cout << "Quote Constructor taking two parameters" << endl;
    }
    //�������캯��
    Quote(const Quote& item) : bookNo(item.bookNo), price(item.price)
    {
        cout << "Quote Copy Constructor" << endl;
    }
    //������ֵ�����
    Quote& operator=(const Quote& item)
    {
        bookNo = item.bookNo;
        price = item.price;
        cout << "Quote Copy assignment operator" << endl;

        return *this;
    }

    //�ƶ����캯��
    Quote(Quote&& item) noexcept : bookNo(std::move(item.bookNo)), price(std::move(item.price))
    {
        cout << "Quote Move Constructor" << endl;
    }

    //�ƶ���ֵ�����
    Quote& operator=(Quote&& item) noexcept
    {
        bookNo = std::move(item.bookNo);
        price = std::move(item.price);
        cout << "Quote Move assignment operator" << endl;

        return *this;
    }

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

    //�������������ж�̬��
    virtual ~Quote()
    {
        cout << "Quote Destructor" << endl;
    }

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
