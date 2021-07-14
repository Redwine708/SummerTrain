#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<functional>
using namespace std;


int main()
{
    int n = 0;
    while(cin>>n && n)
    {
        getchar();
        int totalScore = ( n + 1 ) / 2;
        int fScore = 0 ; int sScore = 0;
        string fGet; string sGet;
        string text;
        for(int i = 0 ; i < n ; i ++)
        {
            if( i % 2 == 0)
            {
                getline(cin,text);
                string tmp = text.substr(text.size() - 7 , 2 );
                //cout<<tmp<<endl;
                if(tmp == "no")fGet += "X ";
                else{ fScore ++ ; fGet += "O ";}
            }  
            else{
                getline(cin,text);
                string tmp = text.substr(text.size() - 7 , 2 );
                //cout<<tmp<<endl;
                if(tmp == "no")sGet += "X ";
                else{ sScore ++ ; sGet += "O ";}
            }
        }
        if( n % 2 == 1)
        {
            sGet += "- ";
        }
        fGet += to_string(fScore);
        sGet += to_string(sScore);
        for(int i = 1 ; i <= (n + 1) / 2  ; i ++)
        {
            cout<<i<<" ";
        }
        cout<<"Score"<<endl;
        cout<<fGet<<endl<<sGet<<endl;
    }
}