#include<sstream>
#include<algorithm>
#include<iterator>
#include "ex12_30.h"

TextQuery::TextQuery(ifstream& ifs) : input(new vector<string>)
{
    LineNo lineNo{0};
    for (string line; getline(ifs, line); ++lineNo) {
        input->push_back(line);
        istringstream line_stream(line);
        for (string text, word; line_stream >> text; word.clear()) {
            remove_copy_if(text.begin(), text.end(), back_inserter(word), ispunct);

            auto &nos = result[word];
            if (!nos) nos.reset(new set<LineNo>);
            nos->insert(lineNo);
        }
    }
}

QueryResult TextQuery::query(const string& str) const
{
    static shared_ptr<set<LineNo>> nodata(new set<LineNo>);
    auto found = result.find(str);
    if (found == result.end())
        return QueryResult(str, nodata, input);
    else
        return QueryResult(str, found->second, input);

}

ostream& print(ostream& out, const QueryResult& qr)
{
    out << qr.word << " occurs " << qr.nos->size() << (qr.nos->size() > 1 ? "times" : "time") << endl;
    for (auto i : *qr.nos)
        out << "\t(line) " << i + 1 << ") " << qr.input->at(i) << endl;

    return out;
}
