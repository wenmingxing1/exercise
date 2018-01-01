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
    auto q = p;     //q指向最后
    while (ifs >> s && q != p+n) alloc.construct(q++, s);   //构造

    while (q != p)
    {
        //反向输出
        cout << *--q << " ";
        //--q;
        alloc.destroy(q);   //销毁
    }

    alloc.deallocate(p, n); //释放内存
}

int main()
{
    input_reverse_output_string(5);

    return 0;
}
