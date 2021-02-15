#include"Message.h"

void Message::save(Folder &f)
{
    folders.insert(&f);
    f.addMsg(this);
}

void Message::remove(Folder &f)
{
    folders.erase(&f);
    f.remMsg(this);
}

void Message::add_to_folders(const Message& m)
{
    for(auto f: m.folders)
    {
        f -> addMsg(this);
    }
}

Message::Message(const Message& m):contents(m.contents),folders(m.folders)
{
    add_to_folders(m);

}

Message::Message(Message&& m)
{
    contents = std::move(m.contents);
    movefolder(&m);

}
Message& Message::operator=(Message &&m)
{
    if(this != &m)
    {
        remove_from_folders();
        contents = std::move(m.contents);
        movefolder(&m);    
    }
     return *this;
}
void Message::movefolder(Message *m)
{
    folders = std::move(m -> folders);
    for(auto &f :folders)
    {
        f -> remMsg(m);
        f -> addMsg(this);
    }
    m -> clear();
}
void Message::remove_from_folders()
{
    for(auto f:this -> folders)
    {
        f -> remMsg(this);
    }
}
Message::~Message()
{
    remove_from_folders();
}

Message& Message::operator=(const Message &m)
{
    remove_from_folders();
    contents = m.contents;
    folders = m.folders;
    add_to_folders(m);
    return *this;
}

void swap(Message &m1, Message &m2)
{
    using std::swap;
    for(auto f : m1.folders)
    {
        f -> remMsg(&m1);
    }
    for(auto f : m2.folders)
    {
        f -> remMsg(&m2);
    }
    swap(m1.folders, m2.folders);
    swap(m1.contents, m2.contents);
    for(auto f : m1.folders)
    {
        f -> addMsg(&m1);
    }
    for(auto f : m2.folders)
    {
        f -> addMsg(&m2);
    }
}

void Folder::add_to_Message(const Folder& f)
{
    for(auto m : f.m_set)
    {
        m->addfolder(this);
    }
}
Folder::Folder(const Folder& f)
{
    add_to_Message(f);
    m_set = f.m_set;
}

 void Folder::remove_from_Message()
 {
     for(auto m : this ->m_set)
     {
         m -> remfolder(this);
     }
 }

 Folder::~Folder()
 {
     remove_from_Message();
 }

 Folder& Folder::operator=(const Folder& f)
 {
     remove_from_Message();
     add_to_Message(f);
     m_set = f.m_set;
     return *this;
 }

 int main()
 {
     return 0;
 }