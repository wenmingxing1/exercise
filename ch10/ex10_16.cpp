#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<fstream>

using namespace std;

//É¾³ýÖØ¸´ÔªËØ
void elimdups(vector<string>& vs) {
    sort(vs.begin(), vs.end());
    auto new_end = unique(vs.begin(), vs.end());
    vs.erase(new_end, vs.end());
}

void biggies(vector<string>& vs, size_t sz) {
    elimdups(vs);

    stable_sort(vs.begin(), vs.end(),
                [](const string& str1, const string& str2){return str1.size()<str2.size();});

    auto wc = partition(vs.begin(), vs.end(),
                        [sz](const string& str) {return str.size() >= sz;});    //²¶»ñsz

    int num = 0;
    cout << "all the letter whose length more than " << sz << " are : " << endl;
    for (auto iter = vs.begin(); iter != wc; ++iter){
        ++num;
        cout << *iter << " ";
    }
    cout << endl << "the number of letters is :" << num << endl;
}

int main()
{
    ifstream ifs("./data/input.txt");
    vector<string> vec;
    string word;
    while (ifs >> word)
        vec.push_back(word);

    biggies(vec, 3);

    return 0;


}

