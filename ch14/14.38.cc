#include<iostream>
#include<fstream>
#include<string>

using namespace std;

class is_length
{
public:
    is_length(size_t s):sz(s){}
    bool operator()(string s)
    {
        return s.size() == sz;
    }
private:
    size_t sz;
};

int main()
{
    
    for(size_t i = 1; i<=10; ++i)
    {
        ifstream ifs("./456.txt");
        is_length a{i};
        int count = 0;
        string word;
        while(ifs >> word)
        {
            if(a(word))
            {
                ++count;
            }
        }
        cout << "size = " << i << " : " << count << endl;
    }

    return 0;
}