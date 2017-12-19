#ifndef SALES_DATA_H_INCLUDED
#define SALES_DATA_H_INCLUDED

#include<string>
using namespace std;

//����Sales_data��
class Sales_data
{
public:
    //��ӹ��캯��
    Sales_data() = default; //Ĭ�Ϲ��캯��
    Sales_data(const string& s) : bookNo(s) {}   //��s����ʼ��bookNo��������Ĭ�ϳ�ʼ��
    Sales_data(const string &s, unsigned n, double p) :
        bookNo(s), units_sold(n), revenue(p*n) {}   //���캯����ʼֵ�б�
    Sales_data (istream&);  //ͨ�����������幹�캯������ֻ����������Ҫ�����ⶨ��

    string isbn() const {return bookNo;}
    Sales_data& combine(const Sales_data&);
    double avg_price() const;

    string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
};

//���ⶨ���Ա����
Sales_data& Sales_data::combine(const Sales_data &rhs) {    //ģ��+=����������Է���Ϊ�������ͣ���һ����ֵ
    units_sold += rhs.units_sold;
    revenue += rhs.revenue;
    return *this;   //���ض���
}

//ƽ���۸�
double Sales_data::avg_price() const {
    if (units_sold)
        return revenue/units_sold;
    else
        return 0;
}

//���⺯������
istream& read(istream& is, Sales_data& item)   //���뺯��
{
    double price;
    is >> item.bookNo >> item.units_sold >> price;
    item.revenue = item.units_sold * price;
    return is;
}
ostream& print(ostream& os, Sales_data& item)  //��ӡ����
{
    os << item.isbn() << " " << item.units_sold << " " << item.revenue << " " << item.avg_price();
    return os;
}

//�ӷ�����
Sales_data add(const Sales_data &item1, const Sales_data &item2) {
    Sales_data newBook;
    if (item1.bookNo == item2.bookNo){
        newBook.units_sold = item1.units_sold + item2.units_sold;
        newBook.revenue = item1.revenue + item2.revenue;
    }
    return newBook;
}

//���ⶨ�幹�캯��
Sales_data::Sales_data(istream &is){
    read(is, *this);    //read�����������Ǵ�is�ж�ȡ��Ϣ����this��
}

#endif // SALES_DATA_H_INCLUDED
