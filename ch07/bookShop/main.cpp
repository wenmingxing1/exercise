#include<iostream>
#include "Sales_data.h"
//using namespace std;

int main()
{
    Sales_data total;
    //����total��Ϣ
    cout << "Please input the total's isbn, numbers, and price:" << endl;
    if (read(cin, total)) {
        Sales_data trans;
        //��������Ϣ
        while (read(cin, trans)) {
            if (total.isbn() == trans.isbn()) {     //�ж��Ƿ���֮ǰ��Ϣ��ͬ
                total.combine(trans);   //������Ϣ
            }
            //����ͬ
            else {
                print(cout, total) << endl;     //�������Ϣ
                total = trans;      //������һ��Ϣ
            }
        }
        print(cout, total) << endl; //������һ��
    }
    //û����Ϣ����
    else{
        cerr << "No data!" << endl;
    }
}
