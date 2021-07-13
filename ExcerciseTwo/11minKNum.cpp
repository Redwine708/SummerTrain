#include<set>
#include<iostream>
using namespace std;

int main()
{
    set<int> contain;
    int n = 0 ; int k = 0;
    cin>>n>>k;
    int num;
    for(int i = 0 ; i < n ; i ++)
    {
        cin>>num;
        if(contain.find(num) == contain.end())
        {
            contain.insert(num);
        }
    }
    if(contain.size() <= k )
    {for(auto&v : contain)
    {
        cout<<v<<" ";
    }
    }   
    else {
        int t = 0;
        for(set<int>::iterator iter = contain.begin() ; t < k ;iter++)
        {
            cout<<*iter<<" ";t++;
        }
    }

}