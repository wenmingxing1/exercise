#include<iostream>
#include<string>
using namespace std;

istream& func(istream& is) {
    string buf;
    while (is >> buf){
        cout << buf << endl;
    }
    is.clear();  //�������и�λ
    return is;
}

int main()
{
    istream &is = func(cin);

    cout << is.rdstate() << endl;   //rdstate()�������ĵ�ǰ״̬

    return 0;
}
