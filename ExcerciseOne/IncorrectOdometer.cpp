#include<iostream>
using namespace std;
long long int perform();
int main()
{
    int T = 0;
    cin>>T;
    while(T--)
    {
        cout<<perform();
    }
}
long long int perform()
{
    long long int  origin = 0;
    cin>>origin;
    long long int count = 0;
    for(long long int i = 1 ; i <= origin ; i ++)
    {
        if( i%10 == 3 || i%10 == 8)count++;
    }
    return origin - count;
}