#include<iostream>
#include<unordered_map>
#include<string>
using namespace std;

unordered_map<string,int> hash1;
string weekday[7] = {"monday","tuesday","wednesday","thursday","friday","saturday", "sunday"};
void make_table()
{
    for(int i = 0 ; i < 7 ; i ++)
    {
        hash1[ weekday[i] ] = i + 1;
    }
} 

int main()
{
    make_table();
    // string m;
    // for(int i = 0 ; i < 7 ; i ++)
    // {
    //     cin>>m;
    //     cout<<hash1[ m ];
    // }
    int t  = 0 ; 
    cin>> t;
    string text1,text2;
    int left, right;
    while(t--)
    {
        cin>>text1>>text2;
        int interval = hash1[text2] - hash1[text1] + 1 ;
        int result = 0;
        int first = 0;
        cin>>left>>right;
        // if(left > interval)
        // {
        //     cout<<"impossible"<<endl;
        //     continue;
        // }
        int duringDays = interval ;
        while( duringDays <= right  )
        {
            if( duringDays >= left /*&& duringDays <= right*/ )
            {
                result++;
                first = duringDays;
            }
            duringDays += 7;
        }
        if(result == 1)cout<<first<<endl;
        else if(result > 1)cout<<"many"<<endl;
        else cout<<"impossible"<<endl;
        
    }
}