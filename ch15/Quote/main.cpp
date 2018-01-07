#include "../ex15_03_Quote.h"
#include "../ex15_05_Bulk_quote.h"
#include "../ex15_15_Disc_quote.h"
#include "../ex15_15_Disc_Bulk_quote.h"

int main()
{
    cout << "========================ex03=========================" << endl;
    Quote quote_03("0-201-78345-X", 23.8);
    print_total(cout, quote_03, 3);
    cout << endl << endl;

    cout << "========================ex05=========================" << endl;
    Bulk_quote bulk("0-201-78345-X", 23.8, 5, 0.5);
    cout << "no discount:" << endl;
    print_total(cout, bulk, 4);
    cout << "have discount:" << endl;
    print_total(cout, bulk, 5);
    cout << endl << endl;

    cout << "========================ex11=========================" << endl;
    quote_03.debug();
    bulk.debug();
    cout << endl << endl;

    cout << "========================ex15=========================" << endl;
    //Disc_quote test;    //error,测试为实例化抽象基类
    Disc_Bulk_quote disc_bulk("0-201-78345-X", 23.8, 5, 0.5);
    cout << "have discount:" << endl;
    print_total(cout, disc_bulk, 5);
    cout << endl << endl;

    cout << "========================ex26=========================" << endl;
    Quote quote_26;
    Bulk_quote bulk_quote_26;   //应该输出两个

    Quote quote_26_2("ligang", 23.8);
    Quote quote_26_3(quote_26_2);

    Quote quote_26_4(std::move(quote_26_2));
    cout << endl << endl;









    return 0;
}
