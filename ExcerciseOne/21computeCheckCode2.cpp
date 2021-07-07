//It is a math problem
//a ^ b mod c = (a mod c) ^ b
#include<string>
#include<cmath>
#include<iostream>
#include<map>
using namespace std;
map<char , int > hash2 ;
void make_hash()
{
    for(int i = 0 ; i < 10 ; i ++)
    {
        hash2 [char( i + '0')] = i;
    }
    for(int i = 0 ; i < 6 ; i ++)
    {
        hash2[ char(i + 'a') ] = 10 + i;
    }
}
int main()
{
    make_hash();
    int t = 0;
    cin>>t;
    while(t--)
    {
        int flag = 0;
        int result = 0;
        string str; int b;
        cin>>b>>str;
        for(int i  = 0 ; i<str.size() ; i ++)
        {
            result+= hash2[str[i]];
        }
        for(int i = 0 ; i < b; i ++)
        {
            if((result + i) %( b - 1) == 0)
            {
                flag = i;
                break;
            }
        }
        if(flag < 10)cout<<flag<<endl;
        else
        {
            cout<<char(flag - 10 + 'a')<<endl;
        }
    }
}