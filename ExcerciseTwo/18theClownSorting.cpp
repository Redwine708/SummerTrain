#include<iostream>
#include<vector>
#include<string>
#include<map>
using namespace std;

int main()
{
    int n = 0;
    int t = 1;
    while(cin>>n && n)
    {
        string oldString [n];
        for(int i = 0 ; i < n ; i ++)
        {
            cin>>oldString[i];
        }
        string newString[n];
        int re = 0;
        for(int i = 0 ;  i < n ; i ++)
        {
            if(re < n){
            newString[i] = oldString[re];
            if(re + 1 < n )newString[n - i - 1 ] = oldString[re+1];
            re+=2;
            }
            else break;
        }
        cout<<"set-"<<t++<<endl;
        for(int i = 0 ; i < n ; i ++)
        {
            cout<<newString[i]<<endl;
        }
    }
}
