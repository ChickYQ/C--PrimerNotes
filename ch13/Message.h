#include<iostream>
#include<set>
#include<string>

using namespace std;
class Folder;


class Message{
friend class Folder;
friend void swap(Message&, Message&);
public:
    explicit Message(const string &str = ""):contents(str){}
    Message(const Message&);
    Message(Message&&);
    Message& operator=(const Message&);
    Message& operator=(Message&&);
    ~Message();
    void save(Folder&);
    void remove(Folder&);
    void clear(){folders.clear();}
private:
    string contents;
    set<Folder*> folders;
    void addfolder(Folder *m){folders.insert(m);}
    void remfolder(Folder *m){folders.erase(m);}
    void movefolder(Message *);
    void add_to_folders(const Message&);
    void remove_from_folders();
};

class Folder{
    friend class Message;
    friend void swap(Folder&, Folder&);
public:
    Folder();
    Folder(const Folder&);
    Folder& operator=(const Folder&);
    void addMsg(Message *m){m_set.insert(m);}
    void remMsg(Message *m){m_set.erase(m);}
    ~Folder();
private:
    void add_to_Message(const Folder&);
    void remove_from_Message();
    set<Message*> m_set;
};
void swap(Folder&, Folder&);
void swap(Message&, Message&);

