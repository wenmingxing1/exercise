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
    TextQuery(ifstream&);   //���캯��
    QueryResult query(const string&) const;

private:
    shared_ptr<vector<string>> input;   //��Ϊ��������Ҫ�������ݣ����Զ�������ָ��
    map<string, shared_ptr<set<LineNo>>> result;    //set�д���кţ���֤���ظ�
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

ostream& print(ostream&, const QueryResult&);   //����������

#endif // EX12_30_H_INCLUDED
