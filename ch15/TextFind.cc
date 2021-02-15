#include"TextFind.h"
#include<sstream>
TextQuery::TextQuery(ifstream &ifs):text(new StrVec)
{
    string line;
    while(getline(ifs,line))
    {
    
        text -> push_back(line); 
        istringstream iss(line);
        string word;
        while(iss >> word)
        {   if(!word_to_line[word])
            word_to_line[word].reset(new set<int>);
            word_to_line[word] -> insert(text -> size() - 1);
        }
    }
}

QueryResult TextQuery::query(const string &word) const 
{
    auto iter = word_to_line.find(word);
    if(iter != word_to_line.end())
    {
        return QueryResult(word, iter -> second, text);
    }else
    {
        return QueryResult(word, shared_ptr<set<int>>(new set<int>({-1})), text);
    }
    
}

ostream& print(ostream &os, const QueryResult &qr){

    if(*((*(qr.lines)).begin()) == -1)
    {
        os << "can not find word" << endl;
        return os;
    }else
    {
        os << qr.word << " occurs " << qr.lines ->size() << " times " << endl;
        for(auto num : *qr.lines)
        {
            os <<"\t(line" << num + 1 << ") " << *((*qr.text).begin()+num) << endl;
        }
        return os;
    }
    
}
/*
int main()
{
    ifstream ifs("./456.txt");
    TextQuery tq(ifs);
    string word;
    while(cin >> word)
    {
        print(cout,tq.query(word)) << endl;
    }
    return 0;
}*/