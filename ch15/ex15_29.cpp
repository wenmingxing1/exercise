#include "ex15_05_Bulk_quote.h"
#include<vector>
#include<numeric>
#include<memory>

int main()
{
    //以指针形式存储则计算结果相同，因为存在动态绑定
    vector<shared_ptr<Quote>> vecQuote;

    shared_ptr<Bulk_quote> spBulk0 = make_shared<Bulk_quote>("0-201-82470-1", 50, 5, 0.2);
    shared_ptr<Bulk_quote> spBulk1 = make_shared<Bulk_quote>("0-201-82470-1", 50, 3, 0.5);

    cout << "bulk_quote's total should be : " << spBulk0->net_price(5) + spBulk1->net_price(5) << endl;

    vecQuote.push_back(spBulk0);
    vecQuote.push_back(spBulk1);

    double total = accumulate(vecQuote.cbegin(), vecQuote.cend(), 0.0, [](double ret, shared_ptr<Quote> sp)
                                                                        { return ret += sp->net_price(5);});

    cout << "total in the vector: " << total << endl;

    return 0;
}
