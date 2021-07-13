#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

int main()
{
    int n = 0;
    while(cin>>n && n)
    {
        string result = "";
        string text;
        cin>>text;
        //reverse(text.begin(),text.end());
        //cout<<text;
        for(string::iterator iter = text.begin() ; iter != text.end() ; iter++)
        {
            string tmp(iter, text.end());
            string tmp2 = tmp;
            reverse(tmp2.begin(), tmp2.end() );
            if(tmp == tmp2){
                result = tmp;
                break;
            }
        }
        cout<<text.size() - result.size()<<endl;

    }
}