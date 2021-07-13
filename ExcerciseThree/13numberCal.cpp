#include<iostream>
#include<algorithm>
#include<string>
#include<sstream>
#include<vector>
#include<map>
using namespace std;

int main()
{
    string t;
    cin>>t;
    map<char,int>table;
    for(int i = 0 ; i < t.size() ; i ++)
    {
        table[ t[i] ]++;
    }
    for(auto&v : table)
    {
        cout<<v.first<<":"<<v.second<<endl;
    }
}


