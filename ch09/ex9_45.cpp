#include<iostream>
#include<string>

using namespace std;

const string& add(string& name, const string& fr, const string& be) {
    name.insert(name.begin(), fr);
    name.append(be);

    string name_new = name;
    return name_new;
}

int main()
{
    string name = "LiGang";
    string fr, be;
    cin >> fr;
    cin >> be;

    cout << add(name, fr, be) << endl;

    return 0;
}
