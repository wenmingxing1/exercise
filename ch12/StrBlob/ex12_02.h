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
    StrBlob() : data(make_shared<vector<string>>()) {};   //Ĭ�Ϲ��캯��
    StrBlob(initializer_list<string> il) : data(make_shared<vector<string>>(il)) {};   //һ������initializer_list�Ĺ��캯��
    size_type size() const {return data->size();}
    bool empty() const {return data->empty();}

    //��Ӻ�ɾ��Ԫ��
    void push_back(const string &t) {data->push_back(t);}
    void pop_back();

    //Ԫ�ط���
    string& front();
    string& back();

    //const����Ԫ�ط��ʺ���
    const string& front() const;
    const string& back() const;

private:
    shared_ptr<vector<string>> data;
    //�����������Ƿ��ںϷ���Χ�ڣ�����pop_back��front��back����
    void check(size_type i, const string &msg) const;
};

void StrBlob::check(size_type i, const string &msg) const {
    if (i >= data->size())
        throw out_of_range(msg);
}

string& StrBlob::front()
{
    //���ȼ��vector�Ƿ�Ϊ��
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
