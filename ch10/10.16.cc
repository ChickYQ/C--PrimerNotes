#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;

void biggies(vector<string> &v1 , vector<string>::size_type sz)
{
    sort(v1.begin(),v1.end());
    auto unique_it = unique(v1.begin(),v1.end());
    v1.erase(unique_it,v1.end());
    stable_sort(v1.begin(),v1.end(),[](const string &s1, const string &s2){return s1.size() < s2.size();});
    auto wc = find_if(v1.begin(), v1.end(), [sz](const string &s1){return s1.size() >= sz;});
    for_each(wc, v1.end(),[](const string &s){cout << s << " ";});
    cout << endl;
   // auto it = partition(v1.begin(),v1.end(),is_length_five);
}
int main()
{
    auto sum1 = [](int a, int b){return a + b;};
    auto sum1_result = sum1(1,2);
    cout << sum1_result << endl;

    int a = 4;
    auto sum2 =[a](int b){return a + b;};
    auto sum2_result = sum2(2);
    cout << sum2_result << endl;

    vector<string> v1;
    string str;
    while(cin >> str)
    {
        v1.push_back(str);
    }
    biggies(v1,4);

    return 0;


}