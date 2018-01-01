#include "ex12_30.h"

using namespace std;

void runQueries(ifstream& infile)
{
    //infileΪ����Ҫ������ļ�
    TextQuery tq(infile);   //����tq�������ļ���������ѯmap

    //�û�������ʽ
    while(1) {
        cout << "enter word to look for, or q to quit:" << endl;
        string s;
        //��������ļ�β���û�ѡ���˳�����
        if (!(cin >> s) || s == "q") break;
        //ָ���ѯ����ӡ���
        print(cout, tq.query(s)) << endl;
    }
}



int main()
{
    ifstream file("./data/story.txt");
    runQueries(file);

    return 0;
}
