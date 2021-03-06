#ifndef EX12_19_H_INCLUDED
#define EX12_19_H_INCLUDED

#include<iostream>
#include<string>
#include<memory>
#include<initializer_list>
#include<vector>
#include<exception>

using namespace std;

class StrBlobPtr;

class StrBlob
{
    using size_type = vector<string>::size_type;
    friend class StrBlobPtr;

public:
    StrBlob() : data(make_shared<vector<string>>()) {}
    StrBlob(initializer_list<string> il) : data(make_shared<vector<string>>(il)) {}

    size_type size() const {return data->size();}
    bool empty() const {return data->empty();}

    void push_back(const string& t) {data->push_back(t);}
    void pop_back() {
        check(0, "back on empty StrBlob!");
        return data->pop_back();
    };

    string& front() {
        check(0, "front on empty StrBlob!");
        return data->front();
    }

    const string& front() const {
        check(0, "front on empty StrBlob!");
        return data->front();
    }

    string& back() {
        check(0, "back on empty StrBlob!");
        return data->back();
    }

    const string& back() const {
        check(0, "back on empty StrBlob!");
        return data->back();
    }

private:
    void check(size_type i, const string& msg) const {
        if (i >= data.size())
            throw out_of_range(msg);
    }

    shared_ptr<vector<string>> data;
};


class StrBlobPtr
{
public:
    StrBlobPtr() : curr(0) {}
    StrBlobPtr(StrBlob& a, size_t sz = 0) : wptr(a.data), curr(sz) {}
    bool operator!=(const StrBlobPtr& p) {return p.curr != curr;}
    //解引用
    string& deref() const {
        auto p = check(curr, "dereference past end");
        return (*p)[curr];
    }
    //递增
    StrBlobPtr& incr() {
        check(curr, "increment past end of StrBlobptr");
        ++curr;
        return *this;
    }

private:
    size_t curr;
    weak_ptr<vector<string>> wptr;

    shared_ptr<vector<string>> check(size_t i, const string& msg) const {
        auto ret = wptr.lock(); //判断是否存在
        if (!ret) throw runtime_error("unbound StrBlobPtr");
        if (i >= ret->size()) throw out_of_range(msg);
        return ret;
    }
};

#endif // EX12_19_H_INCLUDED
