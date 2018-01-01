#include "ex12_30.h"

using namespace std;

void runQueries(ifstream& infile)
{
    //infile为我们要处理的文件
    TextQuery tq(infile);   //构造tq，保存文件并建立查询map

    //用户交互方式
    while(1) {
        cout << "enter word to look for, or q to quit:" << endl;
        string s;
        //如果遇到文件尾或用户选择退出程序
        if (!(cin >> s) || s == "q") break;
        //指向查询并打印结果
        print(cout, tq.query(s)) << endl;
    }
}



int main()
{
    ifstream file("./data/story.txt");
    runQueries(file);

    return 0;
}
