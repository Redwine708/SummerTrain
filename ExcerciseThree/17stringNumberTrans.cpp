#include<iostream>
#include<string>
#include<vector>
#include<map>
using namespace std;

map<char,string>table;
void make_table()
{
    table['0'] = "(Zero)"; table['1'] = "(One)"; table['2'] = "(Two)";
    table['3'] = "(Three)"; table['4'] = "(Four)"; table['5'] = "(Five)";
    table['6'] = "(Six)"; table['7'] = "(Seven)"; table['8'] = "(Eight)";
    table['9'] = "(Nine)";
}
int main()
{
    make_table();
    string text;
    while(getline(cin,text))
    {
        string tmp;
        int count [10] ;
        fill(count,count+10,0);
        for(int i = 0 ; i < text.size() ; i ++)
        {
            if( ! isdigit(text[i]) ) tmp += text[i];
            else{
                tmp+= table[ text[i] ] ;
                count[text[i] - '0']++;
            }
        }
        cout<<tmp<<endl;
        for(int i =  0 ; i< 10 ; i ++)
        {
            cout<<count[i]<<" ";
        }
        cout<<endl;
    }
}
