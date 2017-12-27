#include<string>
#include<iostream>
#include<stack>
using namespace std;

int main()
{
    stack<string> st;
    string word;
    while (cin >> word) {
        int num = 0;
        //stack.push(word);
        if (word == "(") {
            ++num;
            st.push(word);
        }
        if (word == ")") {
            int sum = 0;
            while (num > 1) {
                string temp = st.pop();
                sum += stoi(temp);
                --num;
            }
            st.pop();
            st.push(sum);
        }
        else {
            st.push(word);
            ++num;
        }
    }
}
