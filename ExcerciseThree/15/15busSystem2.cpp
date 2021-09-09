#include<iostream>
#include<bits/stdc++.h>
#include<algorithm>
#include<cmath>
using namespace std;

int main()
{
    long long int n = 0 ;long long  int busIntake = 0;
    cin>>n>>busIntake;
    long long int* change = new long long int[n+1];
    change[0] = 0;
    
    for(int i = 1 ; i <= n ; i ++)
    {
        cin>>change[i];
    }
    
    for(int i = 2;  i <= n ; i ++)
    {
        change[i] = change[i] + change[i - 1];
    }
    long long int minValue = 0;
    long long int maxValue = LONG_MIN;
    for(int i = 1 ; i <= n ; i ++)
    {
        if(change[i] < 0 && change[i] < minValue)minValue = change[i];
        if(change[i] > maxValue)maxValue = change[i];
    }
    int t = abs(minValue);
    if(busIntake - maxValue + 1 - t >0)cout<<busIntake - maxValue + 1 - t;
    else cout<<0;

}