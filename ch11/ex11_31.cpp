#include<iostream>
#include<map>
#include<string>

using namespace std;

int main()
{
    multimap<string, string> authors {
        { "ligang", "剑指offer" },
        { "ligang", "python基础教程" },
        { "lishuo", "通信原理" }
    };

    string author = "ligang";
    string book = "剑指offer";

    //find返回迭代器，如果没找到返回end，erase也返回迭代器。
    for (auto found = authors.find(author);
            found != authors.end() && found->first == author;) {
        if (found->second == book)
            found = authors.erase(found);
        else
            ++found;
    }

    for (const auto& author : authors)
        cout << "author.first" << " " << author.second << endl;

    return 0;
}
