#include<iostream>
#include<string>
#include<fstream>

using namespace std;

int main()
{
    ifstream ifs("./data/letter.txt");
    ofstream output("./data/out.txt");
    if (!ifs) return -1;
    string longest_word;

    for (string word; ifs >> word;) {
        if (word.find_first_not_of("aceimnorsuvwxz") == string::npos && word.size() > longest_word.size()) {
            longest_word = word;
        }
    }

    output << longest_word;
}
