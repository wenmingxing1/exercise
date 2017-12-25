#ifndef BOOKSHOP_H_INCLUDED
#define BOOKSHOP_H_INCLUDED

#include<iostream>
#include<string>
using namespace std;

class Sales_data {
    friend istream& read(istream& is, Sales_data& item);
    friend ostream& print(ostream& os, const Sales_data& item);
    friend Sales_data add(const Sales_data& item1, const Sales_data& item2);
public:
    Sales_data() = default;
    Sales_data(const string& s) : bookNo(s) {}
    Sales_data(const string& s, unsigned n, double p) : bookNo(s), units_sold(n), revenue(n*p) {}
    Sales_data(istream& is) {read(is, *this);}

    string isbn() const {return bookNo;}
    Sales_data& combine(const Sales_data&);

private:
    string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
};

Sales_data& Sales_data::combine(const Sales_data& rhs) {
    units_sold += rhs.units_sold;
    revenue += rhs.revenue;
    return *this;
}

istream& read(istream& is, Sales_data& item){
    double price = 0;
    is >> item.bookNo >> item.units_sold >> price;
    item.revenue = item.units_sold * price;
    return is;
}

ostream& print(ostream& os, const Sales_data& item) {
    os << item.isbn() << " " << item.units_sold << " " << item.revenue;

    return os;
}

Sales_data add(const Sales_data& item1, const Sales_data& item2) {
    Sales_data item = item1;
    item.combine(item2);

    return item;
}

#endif // BOOKSHOP_H_INCLUDED
