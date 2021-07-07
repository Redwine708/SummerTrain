//Attention that the number should be started from two not one
#include<iostream>
#include<string>
#include<sstream>
using namespace std;
bool judge(string text, int size);
bool isRecurrNumber(long long int trans , string text);
int* getNext(string pattern)
{
    int * next = new int[pattern.size()];
    int n = pattern.size();
    int j = -1;
    next[0] = -1;
    for(int i = 1 ; i < n ; i ++)
    {
        while(j != -1 && pattern[j + 1] != pattern[i])
        {
            j = next[j];
        }
        if(pattern[j + 1] == pattern[i])
        {
            j++ ;
        }
        next[i] = j;
    }
    return next;
}
bool KMP(string text , string pattern){
    //get next
    int n = text.size(), m = pattern.size();
    if(n < m)return false;
    int * next = getNext(pattern);
    int j = -1;
    for(int i = 0 ; i < n ; i ++)
    {
        while( j != -1 && text[i] != pattern[j + 1]){
            j = next[j];
        }
        if(text[i] == pattern[j + 1])j++;
        if(j == m - 1)return true;
    }
    //free space
    delete next;
    return false;
}

int main()
{
    string text;
    cin>>text;
    int size = text.size();
    if(judge(text, size) )cout<<"Yes";
    else cout<<"No";
}


bool judge(string text, int size)
{
    istringstream is(text);
    long long int trans; 
    is>>trans;
    //cout<<trans;
    for(int i = 2 ; i < size + 1; i ++)
    {
        if( isRecurrNumber( trans * i, text ) )return true;
    }   
    return false;
}
bool isRecurrNumber(long long int trans, string text)
{
    int size = text.size();
    string tranString = to_string(trans);
    if(tranString.size() < size)
    {
        string leadingSpaces = "";
        int diff = size - tranString.size();
        while(diff--){leadingSpaces+="0";}
        tranString = leadingSpaces + tranString;
    }
    string douText = text + text;
    return KMP(douText,tranString);
}