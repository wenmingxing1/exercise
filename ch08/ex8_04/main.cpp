#include<fstream>
#include<vector>
#include<string>
#include<iostream>

using namespace std;

//8_04函数，以行为分界符
void ReadFileToVec_line(const string &fileName, vector<string>& vec){
    ifstream ifs(fileName);
    if (ifs) {      //如果文件打开成功，则按行读取至buf，并存入vec中
        string buf;
        while (getline(ifs, buf)) vec.push_back(buf);
    }
}

//8_05函数,以空格为分界符
void ReadFileToVec_word(const string &fileName, vector<string>& vec) {
    ifstream ifs(fileName);
    if (ifs) {
        string buf;
        while (ifs >> buf) vec.push_back(buf);
    }
}

int main() {
    vector<string> vec1;
    ReadFileToVec_line("./data/book.txt", vec1);    //相对路径用'/'；绝对路径用'\'
    cout << "输出第一个函数内容:" << endl;
    cout << "----------------" << endl;
    for (const auto& str : vec1) cout << str << endl;
    cout << endl;

    vector<string> vec2;
    ReadFileToVec_word("./data/book.txt", vec2);
    cout << "输出第二个函数内容：" << endl;
    cout << "----------------" << endl;
    for (const auto& str : vec2) cout << str << endl;
    return 0;
}
