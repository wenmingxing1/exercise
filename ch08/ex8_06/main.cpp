#include "BookShop.h"
#include<fstream>
#include<iostream>

using namespace std;

int main(int argc, char** argv)
{
    argv[1] = "./data/book.txt";
    argv[2] = "./data/out.txt";
    ifstream input(argv[1]);    //use "./data/book.txt"
    ofstream output(argv[2]);   //ÿ������д�룬������֮ǰ���нض�
    //ofstream output(argv[2], ofstream::app);    //�趨ģʽΪ׷�ӵ��ļ�ĩβ������ÿ��д�벻ˢ��

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
