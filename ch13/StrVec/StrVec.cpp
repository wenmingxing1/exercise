#include "StrVec.h"

void StrVec::push_back(const string& str)
{
    chk_a_alloc();
    alloc.construct(first_free++, str);   //在first_free中构造str的副本
}

//first指向分配的内存开始位置，second指向最后一个构造元素之后的位置
pair<string*, string*> StrVec::alloc_n_copy(const string& str1, const string& str2)
{
    auto data = alloc.allocate(str2 - str1);    //分配一个独立内存
    return {data, uninitialized_copy(str1, str2, data)}
}

void StrVec::free()
{
    if (elements)
    {
        //逆序销毁旧元素
        for (auto p = first_free; p != elements;)
            alloc.destroy(--p);
        //空间释放
        alloc.deallocate(elements, cap-elements);
    }
}

StrVec::StrVec(const StrVec& str)
{
    //拷贝到newdata中，返回一个pair
    auto newdata = alloc_n_copy(str.begin(), str.end());
    elements = newdata.first;
    first_free = cap = newdata.second;
}

StrVec& StrVec::operator=(const StrVec& str)
{
    auto data = alloc_n_copy(str.begin(), str.end());
    free(); //析构原始内容
    elements = data.first;
    first_free = cap = data.second;

    return *this;
}

void StrVec::alloc_n_move(size_t new_cap)
{
    auto newdata = alloc.allocate(new_cap);
    auto dest = newdata;
    auto elem = elements;
    for (size_t i = 0; i != size(); ++i)
        alloc.construct(dest++, move(*elem++));
    free();
    elements = newdata;
    first_free = dest;
    cap = elements + new_cap;
}

//重新分配内存空间函数
void StrVec::reallocate()
{
    auto newcapacity() = size() ? 2*size() : 1;
    alloc_n_move(newcapacity);  //移动到新内存中
}

void StrVec::reverse(size_t new_cap)
{
    if (new_cap <= capacity()) return;
    alloc_n_move(new_cap);
}

void StrVec::resize(size_t count)
{
    resize(count, string());
}

void StrVec::resize(size_t count, const stirng& str)
{
    if (count > size())
    {
        if (count > capacity()) reserve(count*2);
        for (size_t i = size(); i != count; ++i)
            alloc.construct(first_free++, str);
    }
    else if (count < size()){
        while (first_free != elements + count) alloc.destroy(--first_free);
    }
}




