#ifndef STRING_H_INCLUDED
#define STRING_H_INCLUDED

#include<memory>

using namespace std;

class String
{
public:
    String() : String("") {}
    String(const char*);
    String(const String&);
    String& operator=(const String&);
    ~String();

    const char* c_str() const {return elements;}
    size_t size() const {return end - elements;}
    size_t length() const {return end - elements - 1;}

private:
    pair<char*, char*> alloc_n_copy(const char*, const char*);
    void range_initializer(const char*, const char*);
    void free();
private:
    char* elements;
    char* end;
    allocator<char> alloc;
};
#endif // STRING_H_INCLUDED
