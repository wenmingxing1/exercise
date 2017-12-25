#include "BookShop.h"
#include<fstream>
#include<iostream>

using namespace std;

int main(int argc, char** argv)
{
    argv[1] = "./data/book.txt";
    argv[2] = "./data/out.txt";
    ifstream input(argv[1]);    //use "./data/book.txt"
    ofstream output(argv[2]);   //每次重新写入，不跟随之前，有截断
    //ofstream output(argv[2], ofstream::app);    //设定模式为追加到文件末尾，这样每次写入不刷新

    Sales_data total;
    if (read(input, total)) {
        Sales_data trans;
        while (read(input, trans)){
            if (total.isbn() == trans.isbn())
                total.combine(trans);
            else {
                print(output, total) << endl;
                total = trans;
            }
        }
        print(output, total) << endl;
    }
    else {
        cerr << "No data!" << endl;
    }

}
