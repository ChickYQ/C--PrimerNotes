#include"StrVec.h"
#include<string>
#include<map>
#include<set>
#include<fstream>
#include<memory>
#include<iostream>
using namespace std;
class QueryResult;
class TextQuery
{
public:
    TextQuery(ifstream &ifs);
    QueryResult query(const string& word) const;
private:
    shared_ptr<StrVec> text;
    map<string,shared_ptr<set<int>>> word_to_line; 
};

ostream& print(ostream &os, const QueryResult &qr);
class QueryResult
{
    friend ostream& print(ostream &os, const QueryResult &qr);
public:
    QueryResult(const string &w, shared_ptr<set<int>> line, shared_ptr<StrVec> f):word(w),text(f),lines(line){}
private:
    string word;
    shared_ptr<StrVec> text;
    shared_ptr<set<int>> lines;
};