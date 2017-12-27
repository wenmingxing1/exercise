#include<iostream>
#include<string>
#include<vector>

using namespace std;

int add(const vector<string>& vec) {
    int sum = 0;
    for (auto i : vec) {
        sum += stoi(i)
    }
    return sum;
}

double add(const vector<string>& vec) {
    double sum = 0.0;
    for (auto i : vec) {
        sum += stod(i);
    }
    return sum;
}

int main()
{
    vector<string> vec1{ "1", "2", "3" };
    vector<string> vec2{ "1.1", "2.2", "3.3" };

    int res1 = add(vec1);
    int res2 = add(vec2);

    cout << res1 << " " << res2 << endl;

    return 0;


}
