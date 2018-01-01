#ifndef EX12_30_H_INCLUDED
#define EX12_30_H_INCLUDED

#include<string>
#include<vector>
#include<memory>
#include<iostream>
#include<fstream>
#include<map>
#include<set>

using namespace std;

class QueryResult;

class TextQuery
{
public:
    using LineNo = vector<string>::size_type;
    TextQuery(ifstream&);   //构造函数
    QueryResult query(const string&) const;

private:
    shared_ptr<vector<string>> input;   //因为两个类需要共享数据，所以定义智能指针
    map<string, shared_ptr<set<LineNo>>> result;    //set中存放行号，保证不重复
};

class QueryResult
{
public:
    friend ostream& print(ostream&, const QueryResult&);
public:
    QueryResult(const string& s, shared_ptr<set<TextQuery::LineNo>> set, shared_ptr<vector<string>> v)
    : word(s), nos(set), input(v) {}

private:
    string word;
    shared_ptr<set<TextQuery::LineNo>> nos;
    shared_ptr<vector<string>> input;
};

ostream& print(ostream&, const QueryResult&);   //输出结果函数

#endif // EX12_30_H_INCLUDED
