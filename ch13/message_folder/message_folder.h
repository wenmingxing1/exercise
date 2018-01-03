#ifndef MESSAGE_H_INCLUDED
#define MESSAGE_H_INCLUDED

#include<iostream>
#include<string>
#include<set>

using namespace std;

class Folder;   //声明类

class Message
{
    friend class Folder;    //设为友元类
    friend void swap(Message&, Message&);
    friend void swap(Folder&, Folder&);

public:
    //folders被隐式初始化为空集合
    explicit Message(const string &str = "") : contents(str) { }
    Message(const Message& );   //拷贝构造函数

    Message& operator=(const Message&); //拷贝赋值运算符

    ~Message(); //析构函数

    //从给定Folder集合中添加/删除本Message
    void save(Folder&);
    void remove(Folder&);

    void print_debug();


private:
    string contents;    //实际消息
    set<Folder*> folders;   //包含消息的Folders
    //拷贝构造函数、拷贝赋值运算符所使用的工具函数，设为private
    //将本Message添加到对应的Folders中
    void add_to_Folders(const Message&);
    //从folders中的每个Folder中删除本Message
    void remove_from_Folders();

    void addFldr(Folder* f) {folders.insert(f);}
    void remFldr(Folder* f) {folders.erase(f);}

};

class Folder
{
    friend class Message;
    friend void swap(Message&, Message&);
    friend void swap(Folder&, Folder&);

public:
    Folder() = default;
    Folder(const Folder&);  //
    Folder& operator=(const Folder&);
    ~Folder();

    void print_debug();

private:
    set<Message*> msgs;
    void add_to_Messages(const Folder&);
    void remove_from_Messages();

    void addMsg(Message* m) {msgs.insert(m);}
    void remMsg(Message* m) {msgs.erase(m);}

};

void swap(Message&, Message&);
void swap(Folder&, Folder&);

#endif // MESSAGE_H_INCLUDED
