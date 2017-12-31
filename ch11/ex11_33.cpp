#include<iostream>
#include<string>
#include<map>
#include<fstream>
#include<sstream>

using namespace std;

map<string, string> buildMap(ifstream& map_file) {
    map<string, string> trans_map;
    string key;
    string value;
    //��map_file���뵽key�У�ʣ��ķŵ�value�У��ж�value.size���Ƿ���ת������
    while (map_file >> key && getline(map_file, value)) {
        if (value.size() > 1)
            trans_map[key] = value.substr(1);   //�����ո�
        else
            throw runtime_error("no rule for " + key);
    }

    return trans_map;
}

const string& transform (const string& word, const map<string, string>& m) {
    auto map_it = m.find(word);
    //�������ת������
    if (map_it != m.cend())
        return map_it->second; //���ת��
    else
        return word;   //��ת��
}

//�������
void word_transform(ifstream& map_file, ifstream& input) {
    auto trans_map = buildMap(map_file);    //��ȡת�����򣬱�����trans_map��
    string text;
    while (getline(input, text)) {  //��ȡһ��
        istringstream stream(text);
        string word;
        bool firstword = true;
        while (stream >> word) {    //��ȡÿ������
            if (firstword)
                firstword = false;
            else
                cout << " ";
            cout << transform(word, trans_map); //����ת��
        }
        cout << endl;   //���һ�е�ת��
    }
}

int main()
{
    ifstream ifs_rule("./data/rule.txt");
    ifstream ifs_tran_input("./data/tran_input.txt");
    //ofstream output("./data/tran_output.txt");

    word_transform(ifs_rule, ifs_tran_input);

    return 0;
}
