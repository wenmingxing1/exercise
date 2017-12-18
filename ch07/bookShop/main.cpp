#include<iostream>
#include<string>
using namespace std;

//定义Sales_data类
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

//Sales_data的分成员接口函数
Sales_data add(const Sales_data&, const Sales_data&);
std::ostream &print(std::ostream&, const Sales_data&);
std::istream &read(std::istream&, Sales_data&);

int main()
{
    Sales_data total;
    //输入total信息
    if (read(cin, total)) {
        Sales_data trans;
        //输入新信息
        while (read(cin, trans)) {
            if (total.isbn() == trans.isbn()) {     //判断是否与之前信息相同
                total.combine(trans);   //更新信息
            }
            //若不同
            else {
                print(cout, total) << endl;     //输出旧信息
                total = trans;      //处理下一信息
            }
        }
        print(cout, total) << endl; //输出最后一条
    }
    //没有信息输入
    else{
        cerr << "No data!" << endl;
    }
}
