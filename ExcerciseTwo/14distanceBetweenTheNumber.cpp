#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<map>
#include<cmath>
using namespace std;

int main()
{
    int n = 0;
    cin>>n;
    int num = 0;
    int* store = new int[n];
    for(int i = 0 ; i < n ;i ++)
    {
        cin>>num;
        store[i] = num;
    } 
    sort(store,store+n);
    int result = store[0];
    int Max = store[ n - 1 ]; int Min = store[0];
    int minDistance =  abs(abs(store[0]-Max)-(store[0]-Min));
    for(int i = 1 ; i < n ;i ++)
    {
        int tmp = abs(abs(store[i]-Max)-(store[i]-Min));
        if(tmp < minDistance){
            minDistance = tmp;
            result = store[i];
        }
    }
    cout<<result;
}
