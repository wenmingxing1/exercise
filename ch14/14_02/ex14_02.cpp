#include "ex14_02.h"

istream& operator>>(istream& is, Sales_data& item)
{
    double price = 0.0;
    is >> item.bookNo >> item.units_sold >> price;

    if (is)     //��Ҫ�ж������Ƿ�����
        item.revenue = item.units_sold * price;
    else    //���������򷵻�һ���ն���
        item = Sales_data();

    return is;
}

//��>>��ɹ��캯��
Sales_data::Sales_data(istream& is)
{
    is >> *this;
}

ostream& operator<<(ostream& os, const Sales_data& item)
{
    os << item.isbn() << " " << item.units_sold << " "
       << item.revenue;

    return os;
}

Sales_data& Sales_data::operator+=(const Sales_data& item)
{
    units_sold += item.units_sold;
    revenue += item.revenue;
    return *this;   //����ֵ����Ҫ
}

//�Գ�Ա����+=��ɷǳ�Ա����+
Sales_data operator+(const Sales_data& item1, const Sales_data& item2)
{
    Sales_data sum = item1;
    sum += item2;
    return sum;
}
