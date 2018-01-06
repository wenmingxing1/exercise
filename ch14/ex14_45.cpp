#include<string>
using namespace std;

class Sales_data
{
public:
    explicit operator string() const {return bookNo;}   //类型转换运算符
    explicit operator double() const {return revenue;}
};
