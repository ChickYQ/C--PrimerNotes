#include<iostream>
#include<vector>

using namespace std;

int main()
{
    vector<int> ivec;
    int first;
    while(cin >> first)
    {
        ivec.push_back(first);
        int number;
        while(cin >> number)
        {
            ivec.push_back(number);
        }
        decltype(ivec.size()) index = 0;
        for(index;index<ivec.size()-1;index++)
        {
            cout << "one add next one = " << ivec[index] + ivec[index + 1] << endl;
            if(index <ivec.size() - 1 - index)
            cout << "one add last one = " << ivec[index] + ivec[ivec.size() - 1 - index] << endl;
        }
    }
    return 0;
}