#include <iostream>
#include "person.h"

using namespace std;

int main()
{
    Person person1;  //�����Ĭ�Ϲ��캯��
    Person person2("ligang", "dongchencun");    //����ó�Ա��ʼ���б�Ĺ��캯��

    cout << "Please input person3's name and address(init the person3):" << endl;
    Person person3(cin);    //����õ��������캯��
    //Person person2;
    cout << "Please input person's name and address(init the person1):" << endl;
    read(cin, person1);
    //if (read(read(cin, person), person2)); //������������������������
    print(cout, person1);
    cout << endl;
    print(cout, person2);
    cout << endl;
    print(cout, person3);
    cout << endl;


    return 0;
}
