#include<iostream>
#include<string>

using namespace std;

int main()
{
    string max_word,cur_word,pre_word;
    unsigned max_time = 0,cur_time = 0;
    cin >> pre_word;
    ++cur_time;
    max_word = pre_word;
    while(cin >> cur_word)
    {
        if(cur_word == pre_word)
        {
            ++cur_time;
        }else
        {
            if(cur_time > max_time)
            {
                max_word = pre_word;
                max_time = cur_time;
            }
           cur_time = 1;
           pre_word = cur_word;
        }
        
    }

    cout << "max_word == " << max_word << " max_time == " << max_time <<endl;

    return 0; 
}