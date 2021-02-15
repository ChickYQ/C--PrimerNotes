#include<functional>
#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;
using namespace std::placeholders;

int main(){

    int a[10] = {1,2,3,4,2222,3333,555,6666,2,1};
    auto cont = count_if(begin(a),end(a),bind(greater<int>(),_1,1024)); 
    cout << cont << endl;
    vector<string> v1{"pooh","pooh","po","pooh"};
    auto index = find_if(v1.begin(),v1.end(),bind(not_equal_to<string>(),_1,"pooh"));
    cout << *index << endl;
    transform(begin(a),end(a),begin(a),bind(multiplies<int>(),_1,2));
    for_each(begin(a),end(a),[](int s){cout << s << " ";});
}