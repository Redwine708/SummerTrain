#include<iostream>
#include<vector>
#include<algorithm> 
#include<string>
#include<map>
#include<set>
using namespace std;
map<string,vector<string> >peopleInfo;
int* getNext(string pattern)
{
    int * next = new int[pattern.size()];
    int n = pattern.size();
    int j = -1;
    next[0] = -1;
    for(int i = 1 ; i < n ; i ++)
    {
        while(j != -1 && pattern[j + 1] != pattern[i])
        {
            j = next[j];
        }
        if(pattern[j + 1] == pattern[i])
        {
            j++ ;
        }
        next[i] = j;
    }
    return next;
}
bool KMP(string text , string pattern){
    //get next
    int n = text.size(), m = pattern.size();
    if(n < m)return false;
    int * next = getNext(pattern);
    int j = -1;
    for(int i = 0 ; i < n ; i ++)
    {
        while( j != -1 && text[i] != pattern[j + 1]){
            j = next[j];
        }
        if(text[i] == pattern[j + 1])j++;
        if(j == m - 1 && (i == n - 1 ) )return true;
    }
    //free space
    delete next;
    return false;
}
bool compare(string a, string b)
{
    if(a.size() != b.size() )
    {
        return a.size() < b.size();
    }
    return a < b;
}
int main()
{
    int n = 0;
    cin>>n;getchar();
    string name; string number;
    while(n--)
    {
        cin>>name;getchar();
        getline(cin,number);
        string tmp;
        for(int i = 2 ; i < number.size() ; i ++)
        {
            if(number[i] != ' ')tmp+=number[i];
            else {
                peopleInfo[name].push_back(tmp);
                tmp = "";
            }
        }
        peopleInfo[name].push_back(tmp);
        tmp = "";
    }
    // cout<<"*****************"<<endl;
    // for(auto&v:peopleInfo)
    // {
    //     cout<<v.first<<" ";
    //     for(auto&m:v.second )
    //     {
    //         cout<<m<<" ";
    //     }
    //     cout<<endl;
    // }
    // cout<<"****************"<<endl;
    for(auto& v : peopleInfo)
    {
        sort(v.second.begin(), v.second.end(),compare);
        // cout<<"*************"<<endl;
        // for(auto&m:v.second )
        // {
        //     cout<<m<<" ";
        // }
        // cout<<endl<<"*************"<<endl;
        vector<string> newInfo;
        string name = v.first;
        for(int i = 0 ; i < v.second.size() ; i ++)
        {
            bool flag = true;
            for(int j = i + 1 ; j < v.second.size() ; j ++)
            {
                if( KMP(v.second[j],v.second[i]) == true){
                    flag = false;
                }
            }
            if(flag)
                newInfo.push_back(v.second[i]);
        }
        // newInfo.push_back(v.second[v.second.size() - 1] );
        peopleInfo[name] = newInfo;
    }
    cout<<peopleInfo.size()<<endl;
    for(auto&v:peopleInfo)
    {
        cout<<v.first<<" "<<v.second.size()<<" ";
        for(auto&m:v.second )
        {
            cout<<m<<" ";
        }
        cout<<endl;
    }
}