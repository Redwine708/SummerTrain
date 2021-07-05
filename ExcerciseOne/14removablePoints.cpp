#include<iostream>
using namespace std;
const int MAXSIZE = 2e5;
int main()
{
    int left = 0;int right = 0;
    int x,y;
    int nums = 0;
    cin>>nums;
    while(nums--)
    {
        cin>>x>>y;
        if(x > 0)left++;
        else right++;
    }
    if(left == 1 || right == 1){cout<<"Yes";}
    else cout<<"No";
}