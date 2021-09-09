#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<stack>
using namespace std;

int main(){
    int t = 2;
    map<int,int>poly;
    while(t--){
    int power = 0; int coefficient;
    while(cin>>power>>coefficient && (power || coefficient) )
    {
        poly[power] += coefficient;
    }
    //sort(poly.begin(),poly.end());
    }
    stack<pair<int,int>>result;
    for(auto&v : poly)
    {
        result.push(v);
    }
    
    while(!result.empty())
    {
        pair<int,int>tmp = result.top();
        result.pop();
        if(tmp.second != 0)
            cout<<tmp.first<<" "<<tmp.second<<endl;
    }
    
}