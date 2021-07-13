#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<unordered_map>
using namespace std;
unordered_map<char,char>table;
unordered_map<string,int>table2;
vector<string>table3;
void make_table()
{
    table['A'] = '2'; table['B'] = '2' ; table['C'] = '2' ;
    table['D'] = '3'; table['E'] = '3' ; table['F'] = '3' ; 
    table['G'] = '4'; table['H'] = '4' ; table['I'] = '4' ;
    table['J'] = '5'; table['K'] = '5' ; table['L'] = '5' ;
    table['M'] = '6'; table['N'] = '6' ; table['O'] = '6' ;
    table['P'] = '7'; table['R'] = '7' ; table['S'] = '7' ;
    table['T'] = '8'; table['U'] = '8' ; table['V'] = '8' ;
    table['W'] = '9'; table['X'] = '9' ; table['Y'] = '9' ;
}

bool compare(string a, string b);
int main()
{
//     table['A'] = '2';
//     table['B'] = '2';
//     cout<<table['A']<<endl;
//     cout<<table['B']<<endl;
// 
    //I forgot it again
    make_table();
    int textNums = 0;
    cin>>textNums;
    string text;
    while(textNums--)
    {
        cin>>text;
        string trans;
        int size = text.size();
        //transfer the string to basic string with seven long size
        for(int i = 0 ; i < size ; i ++)
        {
            if(text[i] == '-')continue;
            else if( isalpha(text[i]) )
            {
                trans += table[ text[i] ];
            }
            else trans+= text[i];
        }
        //something wrong
        if(trans.size() != 7 )exit(-1);
        string front;
        for(int i = 0 ; i < 3 ; i ++) front+= trans[i];
        front += '-';
        for(int i = 3 ; i < 7 ; i ++)front+= trans[i];

        if( table2[front] != 0)
        {
            table2[front]++;
        }
        else 
        {
            table2[front]++;
            table3.push_back(front);
        }
    }
    sort(table3.begin(), table3.end() );
    for(int i = 0 ; i < table3.size() ; i ++)
    {
        if(table2[ table3[i] ] > 1){
            cout<<table3[i]<<" "<<table2[ table3[i] ]<<endl;
        }
    }
}
