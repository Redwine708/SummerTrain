#include<iostream>
#include<algorithm> 
#include<cstring> 
using namespace std;
#define INF 9999
//#define MaxN  0x3f3f3f3f
//#define MinN  0xc0c0c0c0
int main()
{
    int x;
    while(cin>>x&&x!=0)
    {
        int n;
        cin>>n;
        int money[n];
        for(int i=0;i<n;i++)
        {
            cin>>money[i];
        }
        sort(money,money+n);
        int dp[x+1];
        for(int i=1; i<=x; ++i) dp[i]=INF; 
        dp[0]=0;
        for(int i=1;i<=x;i++)
        {

            for(int j=0;j<n;j++)
            {
                if(i>=money[j])
                {
                    dp[i]=min(dp[i-money[j]]+1,dp[i]);
                }
            }   
        } 
        if(dp[x]==INF) cout<<"Impossible"<<endl;
        else cout<<dp[x]<<endl;
    }
    return 0;
}

