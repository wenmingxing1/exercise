#include<iostream>
#include<string>
#include<vector>
#include<sstream>
#include<fstream>

using namespace std;

int main()
{
    ifstream ifs("./data/name_numbers.txt");
    if (!ifs) {
        cerr << "No data?!" << endl;
        return -1;
    }

    vector<string> vec;
    string line;
    while (getline(ifs, line)) vec.push_back(line);

    for (auto& s:vec) {
        istringstream iss(s);   //��s��string��iss
        string word;
        while (iss >> word) cout << word << endl;   //��string��iss��word
    }

    return 0;
}
