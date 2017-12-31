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
    //将map_file读入到key中，剩余的放到value中，判断value.size看是否有转换规则
    while (map_file >> key && getline(map_file, value)) {
        if (value.size() > 1)
            trans_map[key] = value.substr(1);   //跳过空格
        else
            throw runtime_error("no rule for " + key);
    }

    return trans_map;
}

const string& transform (const string& word, const map<string, string>& m) {
    auto map_it = m.find(word);
    //如果存在转换规则
    if (map_it != m.cend())
        return map_it->second; //完成转换
    else
        return word;   //不转换
}

//管理程序
void word_transform(ifstream& map_file, ifstream& input) {
    auto trans_map = buildMap(map_file);    //读取转换规则，保存在trans_map中
    string text;
    while (getline(input, text)) {  //读取一行
        istringstream stream(text);
        string word;
        bool firstword = true;
        while (stream >> word) {    //读取每个单词
            if (firstword)
                firstword = false;
            else
                cout << " ";
            cout << transform(word, trans_map); //进行转换
        }
        cout << endl;   //完成一行的转换
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
