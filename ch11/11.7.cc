#include<string>
#include<iostream>
#include<vector>
#include<map>

using namespace std;
void new_famliy(map<string,vector<string>> &famliy, const string &name, const vector<string> &childrens)
{
    famliy[name] = childrens;
}
void add_children(map<string, vector<string>> &famliy, const string &name, const string &children)
{
    famliy[name].push_back(children);
}
int main()
{
    map<string, vector<string>> famliy;
    new_famliy(famliy, "xiaoming", {"m1","m2","m3"});
    new_famliy(famliy, "xiaohong", {"h1","h2","h3"});
    add_children(famliy, "xiaohong", "h4");

    for(auto &f : famliy)
    {
        cout << f.first << " : ";
        for(auto &c : f.second)
        {
            cout << c << " ";
        }
        cout << endl;
    }

    return 0;

}