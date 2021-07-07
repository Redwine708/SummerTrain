#define maxn 10001
#include<iostream>
using namespace std;
int arrayt[maxn];
int main()  
{
    fill(arrayt,arrayt+maxn,0);
    int n ,t;
    int count = 0;
    while(cin>>n)
    {
        int result = 0;
        if(n==0)break;
        while(n--)
        {
            cin>>t;
            arrayt[t]++;
        }
        for(int i = 0 ; i < maxn ; i ++)
        {
            //compare count
            if(count < arrayt[i]) 
            {
                result = i;
                count = arrayt[i];
            }
        }
        cout<<result<<endl;
        //Initialize
        fill(arrayt,arrayt+maxn,0);
        count = 0;
    }
    
}