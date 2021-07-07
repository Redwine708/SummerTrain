#include<string>
#include<cmath>
#include<iostream>
#include<unordered_map>
using namespace std;

unordered_map<char,long long int>table;
unordered_map<long long int,char>table2;
long long int transInt(string n,int b);
char getMode(long long int trans , int b);
void make_table()
{
    table['0'] = 0 ;
    table['1'] = 1 ; table['2'] = 2 ; table['3'] = 3 ; table['4'] = 4;
    table['5'] = 5 ; table['6'] = 6 ; table['7'] = 7 ; table['8'] = 8;
    table['9'] = 9 ;    
    table['a'] = 10; table['b'] = 11; table['c'] = 12; table['d'] = 13;
    table['e'] = 14; table['f'] = 15;
    table2[1] = '1'; table2[2] = '2'; table2[3] = '3'; table2[4] = '4';
    table2[5] = '5'; table2[6] = '6'; table2[7] = '7'; table2[8] = '8';
    table2[9] = '9';
    table2[10] = 'a'; table2[11] = 'b'; table2[12] = 'c'; table2[13] = 'd';
    table2[14] = 'e'; table2[15] = 'f'; 
    table2[0] = '0';
}
int main()
{
    make_table();
    int t = 0;
    cin>>t;
    string n ; int b = 0;
    while(t--){
        cin>>b>>n;
        long long int trans = transInt( n, b );
        cout<< getMode(trans,b) <<endl;
    }
}
long long int transInt(string n , int b){
    long long int result = 0;
    int nSize = n.size()    ;
    for(int i = 0; i <nSize ; i++)
    {
        result += table[ n[i] ] * pow( b , nSize - i - 1 );
    }
    return result;
}
char getMode(long long int trans , int b)
{
    int flag = 0;

    for(long long int i = 0 ; i < b ; i ++)
    {
        long long int tmp = trans * b + i;
        if(tmp % (b - 1) == 0)
        {
            flag = i;
            break;
        }
    }
    char res = table2[flag];
    return res;
}