#include<iostream>
#include<map>
#include<string>

using namespace std;

int main()
{
    multimap<string, string> authors {
        { "ligang", "��ָoffer" },
        { "ligang", "python�����̳�" },
        { "lishuo", "ͨ��ԭ��" }
    };

    string author = "ligang";
    string book = "��ָoffer";

    //find���ص����������û�ҵ�����end��eraseҲ���ص�������
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
