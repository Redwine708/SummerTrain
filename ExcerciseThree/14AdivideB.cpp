#include<iostream>
#include<algorithm>
#include<string>
#include<sstream>
#include<vector>
#include<map>
using namespace std;
pair<string,int> divide(string& text, int nums)
{
    string newText;
    int n = text.size();
    int tmp = 0;
    for(int i = 0 ; i < n ; i ++ )
    {
        int all = tmp * 10 + text[i] - '0';
        int store = all / nums;
        if(i!=0 || store){newText.push_back( store + '0');}
        tmp = all % nums ;
    }
    return make_pair(newText,tmp);
}
int main()
{
    string text;
    int nums = 0;
    cin>>text>>nums;
    if(text[0] != '0'){
    pair<string,int> t =divide(text,nums);
    cout<<t.first<<" "<<t.second;
    }
    else cout<<0<<" "<<0;
}