#include<iostream>
#include<cmath>
using namespace std;

int getALlFactor(long long int n)
{
    int count = 1;
    for(int i = 2 ; i <=sqrt( n) ; i ++ )
    {
        if( n % i == 0){
            count+= ( i + n / i);
        }
    }
    //cout<<count;
    return count;
}

int main()
{
    //getALlFactor(284);
    int m = 0 ; int n = 0;
    while(cin>>m>>n)
    {
        if(m == 0 ||n == 0)exit(-1);
        int mFactor = getALlFactor(m);
        int nFactor = getALlFactor(n);
        if( mFactor==n&& nFactor == m )cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}