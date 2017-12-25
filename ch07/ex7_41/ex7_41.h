#ifndef EX7_41_H_INCLUDED
#define EX7_41_H_INCLUDED

#include<iostream>
#include<string>
using namespace std;

class Sales_data
{
    friend istream& read(istream& is, Sales_data &item);
public:
    Sales_data(string s, unsigned i, double j) : bookNo(s), units_sold(i), revenue(j) {cout << "��ί��"<< endl;}
    //ί�й��캯��
    Sales_data() : Sales_data(" ", 0, 0.0) {cout << "ί�й��캯���е�Ĭ�Ϲ��캯��" << endl;}
    Sales_data(string s) : Sales_data(s, 0, 0.0) {cout << "ί�й��캯���е�ֻ����һ��string�Ĺ��캯��" << endl;}

    Sales_data(istream &is) {read(is, *this);}

private:
    string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
};

istream& read(istream& is, Sales_data &item){
    is >> item.bookNo >> item.units_sold >> item.revenue;
    return is;
}

#endif // EX7_41_H_INCLUDED
