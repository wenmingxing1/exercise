#include "BookShop.h"
#include<fstream>
#include<iostream>

using namespace std;

int main(int argc, char** argv)
{
    argv[1] = "./data/book.txt";
    ifstream input(argv[1]);    //use "./data/book.txt"

    Sales_data total;
    if (read(input, total)) {
        Sales_data trans;
        while (read(input, trans)){
            if (total.isbn() == trans.isbn())
                total.combine(trans);
            else {
                print(cout, total);  //<< endl;
                total = trans;
            }
        }
        print(cout, total);
    }
    else {
        cerr << "No data!" << endl;
    }

}
