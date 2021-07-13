#include<iostream>
#include<stack>
#include<map>
#include<vector>
#include<cmath>
const int TRANS = 26;
using namespace std;

void trans26(stack<long long int>& s,long long int nums)
{
    while(nums)
    {
        long long int mod = nums % TRANS;
        s.push(mod);
        nums /= TRANS;
    }
}

map<char,long long int> table;
void make_table()
{
    for(int i  = 0 ; i < 26 ;i ++)
    {
        table[char('a' + i )] = i;
    }
}

long long int trans10(string& text)
{
    long long int result = 0;
    int n = text.size();
    for(int i = 0 ; i < n ; i ++ )
    {
        result += table[ text[i] ] * pow(26,n - i - 1);
    }
    return result;
}

int main()
{
    make_table();
    int n = 0;
    cin>>n;
    string a,b;
    while(n -- )
    {
        cin>>a>>b;
        long long int a10 = trans10(a);
        long long int b10 = trans10(b);
        long long int c10 = a10 + b10;
        stack<long long int>s;
        trans26(s,c10);
        while(!s.empty())
        {
            int tmp = s.top(); s.pop();
            cout<< char(tmp + 'a');
        }
        cout<<endl;
    }
}


