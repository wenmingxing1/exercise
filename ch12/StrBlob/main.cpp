#include "ex12_02.h"

int main()
{
    const StrBlob csb{ "hello", "world", "ligang" };
    StrBlob sb{ "hello", "world", "lishuo" };

    cout << csb.front() << " " << csb.back() << endl;
    sb.back() = "ligang";
    cout << sb.front() << " " << sb.back() << endl;

    return 0;
}
