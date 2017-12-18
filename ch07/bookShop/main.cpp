#include<iostream>
#include<string>
using namespace std;

//����Sales_data��
class Sales_data
{
public:
    string isbn() const {return bookNo;}
    Sales_data& combine(const Sales_data&);
    double avg_price() const;

private:
    string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;

};

//Sales_data�ķֳ�Ա�ӿں���
Sales_data add(const Sales_data&, const Sales_data&);
std::ostream &print(std::ostream&, const Sales_data&);
std::istream &read(std::istream&, Sales_data&);

int main()
{
    Sales_data total;
    //����total��Ϣ
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
