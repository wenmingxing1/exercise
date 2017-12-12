#include<iostream>
#include<string>
#include "Sales_data.h"

using namespace std;

int main()
{
    Sales_data total;
    double totalPrice;
    cout << "Please input total's bookNo, units_sold, totalPrice" << endl;
    if (cin >> total.bookNo >> total.units_sold >> totalPrice)
        total.CalcRevenue(totalPrice);

    Sales_data book;
    double bookPrice;
    cout << "Please input data's bookNo, units_sold, bookPrice" << endl;
    while (cin >> book.bookNo >> book.units_sold >> bookPrice)
    {
        book.CalcRevenue(bookPrice);

        if (total.bookNo == book.bookNo)
            total.AddData(book);
        else{
            total.SetData(book);
        }

        total.Print();
    }

    return 0;
}
