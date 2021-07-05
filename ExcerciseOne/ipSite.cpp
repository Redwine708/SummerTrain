#include<iostream>
#include<string>
#include<vector>
#include<stack>
#include<unordered_map>
using namespace std;
//CHARGE BY THE METER
//STORE DATE BY STACK AND VECTOR
stack<int> transfer;
unordered_map<int , int > table ;
vector<int> middle;
int count(int i)
{
    int mode = 0;
    while(i)
    {
        mode = i % 2;
        i /=2 ;
        transfer.push(mode);
    }
    int cal = 0;
    while(!transfer.empty())
    {
        int tmp = transfer.top();
        transfer.pop();
        if(tmp == 1){cal++;}
    }
    return cal;
}
void make_table()
{
    for(int i = 0 ; i < 256 ; i ++)
    {
        table[i] = count(i);
    }
}
int result(string text)
{
    int n = text.size();
    int tmp = 0;
    for(int i = 0 ; i < n ; i++)
    {
        if(text[i] != '.')tmp = tmp * 10 + (text[i] - '0');
        else{
            middle.push_back(tmp);
            tmp = 0;
        }
    }
    middle.push_back(tmp);
    vector<int>::iterator iter = middle.begin();
    int result = 0;
    for(; iter != middle.end() ; iter++)
    {
        result += table[(*iter)];
    }
    middle.clear();
    return result;
}
int main()
{
    make_table();
    //text perfectly
    //cout<<table[0];
    int t = 0 ;
    cin>>t;
    while(t--)
    {
        string text;
        cin>>text;
        cout<<result(text)<<endl;
    }
}


