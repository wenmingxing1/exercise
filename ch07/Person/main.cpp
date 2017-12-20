#include <iostream>
#include "person.h"

using namespace std;

int main()
{
    Person person1;  //会调用默认构造函数
    Person person2("ligang", "dongchencun");    //会调用成员初始化列表的构造函数

    cout << "Please input person3's name and address(init the person3):" << endl;
    Person person3(cin);    //会调用第三个构造函数
    //Person person2;
    cout << "Please input person's name and address(init the person1):" << endl;
    read(cin, person1);
    //if (read(read(cin, person), person2)); //可以连续读入两个对象的语句
    print(cout, person1);
    cout << endl;
    print(cout, person2);
    cout << endl;
    print(cout, person3);
    cout << endl;


    return 0;
}
