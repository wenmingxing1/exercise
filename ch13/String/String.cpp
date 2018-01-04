#include "String.h"
#include<algorithm>
#include<iostream>

pair<char*, char*> String::alloc_n_copy(const char* ch1, const char* ch2)
{
    auto str = alloc.allocate(ch2 - ch1);
    return {str, uninitialized_copy(ch1, ch2, str)};
}

void String::range_initializer(const char* first, const char* last)
{
    auto newstr = alloc_n_copy(first, last);
    elements = newstr.first;
    end = newstr.second;
}

String::String(const char* str)
{
    char* s1 = const_cast<char*>(str);
    while (*s1) ++s1;
    range_initializer(str, ++s1);
}

String::String(const String& str)
{
    range_initializer(str.elements, str.end);
    cout << "¿½±´¹¹Ôìº¯Êý" << endl;
}

void String::free()
{
    if (elements)
    {
        for_each(elements, end, [this](char& c) {alloc.destory(&c);});
        alloc.deallocate(elements, end - elements);
    }
}

String::~String()
{
    free();
}

String& String::operaotr=(const String& str)
{
    auto newstr = alloc_n_copy(str.elements, str.end);
    free();
    elements = newstr.first;
    end = newstr.second;
    cout << "¿½±´¸³ÖµÔËËã·û" << endl;
    return *this;
}
