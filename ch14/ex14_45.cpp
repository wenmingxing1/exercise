#include<string>
using namespace std;

class Sales_data
{
public:
    explicit operator string() const {return bookNo;}   //����ת�������
    explicit operator double() const {return revenue;}
};
