#include<set>
#include<map>
#include<iostream>
#include<algorithm>
#include<cctype>

using namespace std;

int main()
{
    map<string, int> wordCount;
    set<string> ignore_word{"the", "or"};
    string word;
    while(cin >> word)
    {
        for(auto &w :word)
        {
            w = tolower(w);
        }
        auto iter = find_if_not(word.begin(), word.end(),[](char ch){return isalpha(ch);});
        string fix_word;
        fix_word = word.substr(0,iter - word.begin());
        cout << fix_word << endl;
        if(ignore_word.find(fix_word) == ignore_word.end())
        {
            ++wordCount[fix_word];
        }
    }

    for(const auto &w : wordCount)
    {
        cout << w.first << " : " << w.second << endl;
    }

    return 0;
}