#include<string>
#include<vector>
#include<map>
#include<iostream>
using namespace std;


int main()
{
    map<long long int,long long int>getPoint;
    int n = 0 ;
    while(cin>>n && n)
    {
        long long int a;long long int b;
        while(n--)
        {
            cin>>a>>b;
            getPoint[a] += b;
        }
        int maxScore = 0;
        int nums = 0;
        for(auto& v : getPoint)
        {
            if(v.second > maxScore)
            {
                maxScore = v.second;
                nums = v.first;
            }
        }
        cout<<nums<<" "<<maxScore<<endl;
    }    
}