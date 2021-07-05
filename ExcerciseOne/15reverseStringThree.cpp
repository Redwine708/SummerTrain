//There is a point whose running time is too long
#include<iostream>
#include<string>
#include<vector>
#define MAXSIZE 1000
using namespace std;
vector<string> reverseSubs;
string reverse(string& goal);
int main()
{
    int textNums = 0;
    cin>>textNums;
    string goal;
    getchar();
    while(textNums--)
    {
        getline(cin,goal);
        cout<<reverse(goal)<<endl;
    }
}

string reverse(string& goal)
{
    int n = goal.size();
    string tmp;
    int count = 0;
    for(int i = 0 ; i < n ; i ++)
    {
        if(goal[i] != ' ') { tmp+=goal[i]; }
        else{
            reverseSubs.push_back(tmp) ;
            tmp = "" ;
            count++  ;
        }
    }
    reverseSubs.push_back(tmp) ;
    count++ ;
    tmp = "" ;
    for(int i = 0 ; i < count; i ++)
    {
        int j = -1 ; int k = reverseSubs[i].size();
        while( ++j < --k )
        {
            swap( reverseSubs[i][j],reverseSubs[i][k] );
        }
        tmp += reverseSubs[i] ;
        tmp += " ";
    }
    tmp.erase( tmp.size() - 1 );
    reverseSubs.clear();
    return tmp;
}