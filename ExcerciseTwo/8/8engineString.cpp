#include<iostream>
#include<algorithm>
#include<string>
#include<sstream>
#include<vector>
#include<map>
using namespace std;

int* getNext(string pattern)
{
    int * next = new int[pattern.size()];
    int n = pattern.size();
    int j = -1;
    next[0] = -1;
    for(int i = 1 ; i < n ; i ++)
    {
        while(j != -1 && pattern[j + 1] != pattern[i] )
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
        if( j == m - 1 && (text [j + 1] == ' ' || i + 1 == n  ) )return true;
    }
    //free space
    delete next;
    return false;
}

vector< pair<string,int> >paper;
bool compare(pair<string,int>a,pair<string,int>b)
{
    return a.second > b.second;
}
int main()
{
    int n = 0;
    cin>>n;
    getchar();
    while(n--)
    {
        string text; int credit = 0;
        getline(cin,text);
        cin>>credit;
        getchar();
        //transform(text.begin(), text.end(), text.begin(), ::tolower);  
        paper.push_back(make_pair( text,credit ) );
    }
    sort(paper.begin(),paper.end(),compare);
    int t = 0 ;
    while(cin>>t && t)
    {
        getchar();
        while(t--){
            vector< pair<string,int> > listPaper;
            string text;
            getline(cin,text);
            transform(text.begin(), text.end(), text.begin(), ::tolower);  
            for(auto&v : paper )
            {
                string tmp = v.first;
                transform(tmp.begin(), tmp.end(), tmp.begin(), ::tolower);
                if( KMP(tmp,text ) )
                {
                    listPaper.push_back( v );
                }
            }
            
            for(auto&v : listPaper)
            {
                cout<<v.first<<endl;
            }
            cout<<"***"<<endl;
        }
        cout<<"---"<<endl;
    }
}