#include<iostream>
#include<vector>
#include<map>
using namespace std;

map<char,string>table;
void make_table()
{
    table['0'] = "ling"; table['1'] = "yi";
    table['2'] = "er"; table['3'] = "san"; table['4'] = "si";
    table['5'] = "wu"; table['6'] = "liu"; table['7'] = "qi";
    table['8'] = "ba"; table['9'] = "jiu"; 
}

int main()
{
    make_table();
    string text;
    while(cin>>text)
    {
        long long int sum = 0;
        for(int i = 0 ;  i< text.size() ; i ++)
        {
            sum += (text[i] - '0');
        }
        string res = to_string(sum);
        for(int i = 0 ; i < res.size() ; i ++)
        {
            cout<<table[res[i] ]<<" ";
        }
        cout<<endl;
    }
}