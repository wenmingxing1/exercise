#include<iostream>
#include<string>
#include<memory>
#include<fstream>

using namespace std;

void input_reverse_output_string(int n)
{
    ifstream ifs("./data/input_string.txt");
    allocator<string> alloc;
    auto const p = alloc.allocate(n);
    string s;
    auto q = p;     //qָ�����
    while (ifs >> s && q != p+n) alloc.construct(q++, s);   //����

    while (q != p)
    {
        //�������
        cout << *--q << " ";
        //--q;
        alloc.destroy(q);   //����
    }

    alloc.deallocate(p, n); //�ͷ��ڴ�
}

int main()
{
    input_reverse_output_string(5);

    return 0;
}
