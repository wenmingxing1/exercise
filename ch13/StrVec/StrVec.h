#ifndef STRVEC_H_INCLUDED
#define STRVEC_H_INCLUDED

#include<string>
#include<memory>
#include<initializer_list>

using namespace std;

class StrVec
{
public:
    StrVec() : elements(nullptr), first_free(nullptr), cap(nullptr) {}
    StrVec(initializer_list<string>);
    StrVec(const StrVec&);
    StrVec& operator=(const StrVec&);
    ~StrVec();

    void push_back(const string&);
    size_t size() {return first_free - elements;}
    size_t capacity() {return cap - elements;}
    string* begin() {return elements;}
    string* end() {return first_free;}

    void reserve(size_t new_cap);
    void resize(size_t count);
    void resize(size_t count, const string&);


private:
    //����������Ҫ��������ڴ�Ĺ��ߺ���
    pair<string*, string*> alloc_n_copy(const string*, const string*);
    void free();
    void chk_a_alloc()      //����Ƿ񳬳����пռ�
    {
        if (size() == capacity()) reallocate();
    }

    void reallocate();  //���·���ռ䣬������

    void alloc_n_move(size_t new_cap);



    string* elements;   //��Ԫ��
    string* first_free;     //��һ����λ��
    string* cap;    //�������һ��
};

#endif // STRVEC_H_INCLUDED
