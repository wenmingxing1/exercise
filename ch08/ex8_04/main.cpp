#include<fstream>
#include<vector>
#include<string>
#include<iostream>

using namespace std;

//8_04����������Ϊ�ֽ��
void ReadFileToVec_line(const string &fileName, vector<string>& vec){
    ifstream ifs(fileName);
    if (ifs) {      //����ļ��򿪳ɹ������ж�ȡ��buf��������vec��
        string buf;
        while (getline(ifs, buf)) vec.push_back(buf);
    }
}

//8_05����,�Կո�Ϊ�ֽ��
void ReadFileToVec_word(const string &fileName, vector<string>& vec) {
    ifstream ifs(fileName);
    if (ifs) {
        string buf;
        while (ifs >> buf) vec.push_back(buf);
    }
}

int main() {
    vector<string> vec1;
    ReadFileToVec_line("./data/book.txt", vec1);    //���·����'/'������·����'\'
    cout << "�����һ����������:" << endl;
    cout << "----------------" << endl;
    for (const auto& str : vec1) cout << str << endl;
    cout << endl;

    vector<string> vec2;
    ReadFileToVec_word("./data/book.txt", vec2);
    cout << "����ڶ����������ݣ�" << endl;
    cout << "----------------" << endl;
    for (const auto& str : vec2) cout << str << endl;
    return 0;
}
