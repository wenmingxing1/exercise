//set & map С��
#include<iostream>
#include<map>
#include<set>
#include<string>
#include<fstream>
#include<algorithm>

using namespace std;

int main()
{
    ifstream ifs("./data/word.txt");
    map<string, size_t> word_count;
    set<string> exc{ ",", ".", ":", ";", "?", "!" };
    string word;
    while (ifs >> word) {
        if (exc.find(word) == exc.end())    //����ҵ��򷵻�����λ�õ����������û���ҵ��򷵻�end������
            ++word_count[word];
    }

    for (auto i : word_count) {
        cout << i.first << " : occurs " << i.second << (i.second > 1 ? "times" : "time") << endl;
    }

    return 0;
}
