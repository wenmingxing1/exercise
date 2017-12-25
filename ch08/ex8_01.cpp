#include<iostream>
#include<string>
using namespace std;

istream& func(istream& is) {
    string buf;
    while (is >> buf){
        cout << buf << endl;
    }
    is.clear();  //对流进行复位
    return is;
}

int main()
{
    istream &is = func(cin);

    cout << is.rdstate() << endl;   //rdstate()返回流的当前状态

    return 0;
}
