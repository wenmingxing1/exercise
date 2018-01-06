#include<iostream>
#include<map>
#include<string>
#include<functional>
#include<algorithm>

using namespace std;

int add(int i, int j) {return i+j;} //��ͨ������ʽ
auto sub = [](int i, int j){return i - j;};  //lambda���ʽ��ʽ
struct mul
{
    int operator() (int i, int j) {return i*j;}     //������������ʽ
};

//divides<int>()    //��׼�⺯��������ʽ

int main()
{
    map<string, function<int(int, int)>> Caculate;
    Caculate.insert({"+", add});    //���ú���ָ�봫��
    Caculate.insert({"-",sub});
    Caculate.insert({"*", mul()});  //���������ഫ��
    Caculate.insert({"/", divides<int>()}); //��׼�⺯������

    cout << "Please input :(�磺10 + 5)" << endl;
    int firstNumber;
    int secondNumber;
    string str;

    while (cin >> firstNumber >> str >> secondNumber)
        cout << Caculate[str](firstNumber, secondNumber) << endl;


    return 0;
}
