#include<vector>
#include<numeric>
#include "ex15_05_Bulk_quote.h"

int main()
{
    vector<Quote> vecQuote;
    Bulk_quote bulk0("0-201-82470", 50, 5, 0.2);
    Bulk_quote bulk1("0-201-82470", 50, 3, 0.5);

    cout << "bulk_quote's total : " << bulk0.net_price(5) + bulk1.net_price(5) << endl;

    vecQuote.push_back(bulk0);
    vecQuote.push_back(bulk1);

    double total = accumulate(vecQuote.cbegin(), vecQuote.cend(), 0.0, [](double ret, const Quote& obj)
                                                                    {return ret += obj.net_price(5);});

    cout << "total in the vector:" << total << endl;

    return 0;
}
