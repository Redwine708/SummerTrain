#include<iostream>
using namespace std;

int main()
{
    long long int n = 0 ;long long  int busIntake = 0;
    cin>>n>>busIntake;
    long long int sum = 0;
    long long int* change = new long long int[n+1];
    for(int i = 1 ; i <= n ; i ++)
    {
        cin>>change[i];
    }
    long long int ans = 0;
    for(int i = 0 ; i <= busIntake ; i ++)
    {
        bool flag =true;
        sum+=i;
        for(int j = 1 ; j <=n ; j ++)
        {
            sum+=change[j];
            if(sum < 0 || sum > busIntake)
            {
                flag =false;
                break;
            }
        }
        if(flag){ans++;}
        if(sum > busIntake)break;   
        sum = 0 ;
        
    }
    cout<<ans;
}