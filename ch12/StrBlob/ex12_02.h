#ifndef EX12_02_H_INCLUDED
#define EX12_02_H_INCLUDED

#include<iostream>
#include<vector>
#include<string>
#include<memory>
#include<exception>

using namespace std;

class StrBlob {
public:
    //typedef vector<string>::size_type size_type;
    using size_type = vector<string>::size_type;
    StrBlob() : data(make_shared<vector<string>>()) {};   //默认构造函数
    StrBlob(initializer_list<string> il) : data(make_shared<vector<string>>(il)) {};   //一个接受initializer_list的构造函数
    size_type size() const {return data->size();}
    bool empty() const {return data->empty();}

    //添加和删除元素
    void push_back(const string &t) {data->push_back(t);}
    void pop_back();

    //元素访问
    string& front();
    string& back();

    //const重载元素访问函数
    const string& front() const;
    const string& back() const;

private:
    shared_ptr<vector<string>> data;
    //检查给定索引是否在合法范围内，用于pop_back，front，back函数
    void check(size_type i, const string &msg) const;
};

void StrBlob::check(size_type i, const string &msg) const {
    if (i >= data->size())
        throw out_of_range(msg);
}

string& StrBlob::front()
{
    //首先检查vector是否为空
    check(0, "front on empty StrBlob!");
    return data->front();
}

const string& StrBlob::front() const {
    check(0, "front on empty StrBlob!");
    return data->front();
}

string& StrBlob::back()
{
    check(0, "back on empty StrBlob!");
    return data->back();
}

const string& StrBlob::back() const {
    check(0, "back on empty StrBlob!");
    return data->back();
}

void StrBlob::pop_back()
{
    check(0, "pop_back on empty StrBlob!");
    return data->pop_back();
}


#endif // EX12_02_H_INCLUDED
