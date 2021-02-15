#include<map>
#include<string>
#include<iostream>

using namespace std;

int main()
{
    multimap<string,string> books;
    books.insert({"cnna", "1"});
    books.insert({"anna", "2"});
    books.insert({"bnna", "3"});
    books.insert({"anna", "4"});
    books.insert({"anna", "5"});
    string author("anna");

    for(auto iter = books.lower_bound(author);iter!=books.upper_bound(author);++iter)
    {
        cout << iter -> second << endl;
    }
    
    return 0;
}