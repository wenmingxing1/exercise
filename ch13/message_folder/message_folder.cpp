#include "message_folder.h"

void swap(Message& ms1, Message& ms2)
{
    ms1.remove_from_Folders();  //从所有folders中删除
    ms2.remove_from_Folders();

    swap(ms1.contents, ms2.contents);
    swap(ms1.folders, ms2.folders);

    ms1.add_to_Folders(ms1);    //添加到folders中
    ms2.add_to_Folders(ms2);
}

//Message
Message::Message(const Message& ms) : contents(ms.contents), folders(ms.folders)
{
    add_to_Folders(ms); //将ms放到folders中
}

Message& Message::operator=(const Message& ms)
{
    remove_from_Folders();
    contents = ms.contents;
    folders = ms.folders;

    add_to_Folders(ms);
    return *this;
}

Message::~Message()
{
    remove_from_Folders();
}

void Message::save(Folder& f)
{
    addFldr(&f);    //放到指定的folders中
    f.addMsg(this);     //将指定的f放到这个message中
}

void Message::remove(Folder& f)
{
    remFldr(&f);
    f.remMsg(this);
}

void Message::print_debug()
{
    cout << contents << endl;
}

void Message::add_to_Folders(const Message& m)
{
    for (auto f : m.folders) f->addMsg(this);
}

void Message::remove_from_Folders()
{
    for (auto f : folders) f->remMsg(this);
}


//Folder

void swap(Folder& fo1, Folder& fo2)
{
    fo1.remove_from_Messages();
    fo2.remove_from_Messages();

    swap(fo1.msgs, fo2.msgs);

    //交换后重新添加回去
    fo1.add_to_Messages(fo1);
    fo2.add_to_Messages(fo2);
}

Folder::Folder(const Folder& fo) : msgs(fo.msgs)
{
    add_to_Messages(fo);
}

Folder& Folder::operator=(const Folder& fo)
{
    remove_from_Messages();
    msgs = fo.msgs;
    add_to_Messages(fo);

    return *this;
}

Folder::~Folder()
{
    remove_from_Messages();
}

void Folder::print_debug()
{
    for (auto m : msgs) cout << m->contents << " ";
    cout << endl;
}

void Folder::add_to_Messages(const Folder& f)
{
    for (auto m : f.msgs) m->addFldr(this);
}

void Folder::remove_from_Messages()
{
    for (auto m : msgs) m->remFldr(this);
}
