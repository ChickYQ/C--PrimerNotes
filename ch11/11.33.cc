#include<map>
#include<string>
#include<iostream>
#include<fstream>
#include<sstream>

using namespace std;

map<string,string> build_map(ifstream &ifs , string &filename);
void transfer(map<string,string> &mp, string &buf);

void transform_word(ifstream &ifs , string &filename)
{
    auto trans_map = build_map(ifs,filename);
    string line;
    while(getline(cin,line))
    {
        istringstream iss(line);
        string word;
        bool first_word = true;
        while(iss >> word)
        {
            if(first_word)
            {
                first_word = false;
            }else
            {
                cout << " ";
            }
            
          transfer(trans_map , word);
          cout << word;
        }
        cout << endl;

    }
}

map<string,string> build_map(ifstream &ifs , string &filename)
{
    ifs.open(filename);
    map<string,string> mp;
    string first,second;
    while(ifs >> first >> second)
    {
        mp.insert({first,second});
    }
    return mp;
}

void transfer(map<string,string> &mp, string &buf)
{

    if(mp.find(buf) != mp.cend())
    {
        buf = mp[buf];
    }else
    {
        ;
    }
    
}

int main()
{
    string filename = "./123.txt";
    ifstream ifs;
    transform_word(ifs,filename);

    return 0;
}