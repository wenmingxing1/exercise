#ifndef MESSAGE_H_INCLUDED
#define MESSAGE_H_INCLUDED

#include<iostream>
#include<string>
#include<set>

using namespace std;

class Folder;   //������

class Message
{
    friend class Folder;    //��Ϊ��Ԫ��
    friend void swap(Message&, Message&);
    friend void swap(Folder&, Folder&);

public:
    //folders����ʽ��ʼ��Ϊ�ռ���
    explicit Message(const string &str = "") : contents(str) { }
    Message(const Message& );   //�������캯��

    Message& operator=(const Message&); //������ֵ�����

    ~Message(); //��������

    //�Ӹ���Folder���������/ɾ����Message
    void save(Folder&);
    void remove(Folder&);

    void print_debug();


private:
    string contents;    //ʵ����Ϣ
    set<Folder*> folders;   //������Ϣ��Folders
    //�������캯����������ֵ�������ʹ�õĹ��ߺ�������Ϊprivate
    //����Message��ӵ���Ӧ��Folders��
    void add_to_Folders(const Message&);
    //��folders�е�ÿ��Folder��ɾ����Message
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
