#include<iostream>
#include<string>
#include<map>
#include<vector>
using namespace std;


int main()
{
    int step = 0;
    int n = 0;
    while(cin>>n && n)
    {
        while(n != 1){
        if( n % 2 == 0){
            n/=2;
            step++;
        }
        else{
            n = 3 * n + 1;
            n /= 2;
            step++;
        }
        }
        cout<<step<<endl;
        //initialize
        step = 0;
    }
    
}