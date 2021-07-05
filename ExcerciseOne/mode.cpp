#define maxn 10006
#include<iostream>
using namespace std;
int arrayt[maxn];
int main()
{
    fill(arrayt,arrayt+maxn,0);
    int n ,t;
    while(cin>>n)
    {
        if(n==0)break;
        while(n--)
        {
            cin>>t;
            arrayt[t]++;
        }
        int result = 0;
        for(int i = 0 ; i < maxn ; i ++)
        {
            if(result < arrayt[i])result = i;
        }
        cout<<result<<endl;
        fill(arrayt,arrayt+maxn,0);
    }
    
}