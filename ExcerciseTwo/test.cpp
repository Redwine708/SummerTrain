#include<iostream>
#include<iostream>
#include<string>
#include<vector>
#include<cstdlib>
#include<unordered_map>
using namespace std;

unordered_map<string,int>hash1;
vector<string>hash2;
int main()
{
    hash1["张三"] = 1;
    hash2.push_back("张三");
    cout<<hash1[hash2[0]]<<endl;
    string t; int m ;
    getline(cin,t);
    cin>>m;
    cout<<t<<" "<<m;

}