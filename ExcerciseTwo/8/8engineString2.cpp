#include<iostream>
#include<algorithm>
#include<string>
#include<sstream>
#include<vector>
#include<map>
using namespace std;

vector< pair<vector<string>, int > >paper;
bool compare(pair<vector<string>, int >a , pair<vector<string>, int >b)
{
    return a.second > b.second;
}

int main()
{
    int n = 0;
    while(cin>>n && n){
        getchar();
    while(n -- )
    {
        vector<string>paperSi;
        string text; int credit = 0;
        getline(cin,text);
        cin>>credit;
        getchar();
        string tmp;
        for(int i = 0 ; i < text.size() ; i ++)
        {
            if(text[i] != ' ')tmp+=text[i];
            else{
                paperSi.push_back(tmp);
                tmp = "";
            }
        }
        paperSi.push_back(tmp);

        paper.push_back( make_pair(paperSi,credit) );
    }
    sort(paper.begin() ,paper.end(),compare);
    int t = 0 ;
    cin>>t;
    getchar();
        while(t--){
            vector< vector<string>  > listPaper;
            string text;
            getline(cin,text);
            transform(text.begin(), text.end(), text.begin(), ::tolower);  
            vector<string>list;
            string tmp;
            for(int i = 0 ; i < text.size() ; i ++)
            {
                if(text[i] != ' ')tmp+=text[i];
                else{
                    list.push_back(tmp);
                    tmp = "";
                }
            }
            list.push_back(tmp);
            for(auto&v : paper)
            {
                int count = 0;
                for(auto& t : v.first )
                {
                    string tmp = t;
                    transform(tmp.begin(),tmp.end(),tmp.begin(),::tolower);
                    for(auto& m : list)
                    {
                        if(m == tmp)count++;
                    }
                }
                if(count == list.size())
                {
                    listPaper.push_back(v.first);
                }
            }
            for(auto&v : listPaper)
            {
                for(auto&t:v)
                {
                    cout<<t<<" ";
                }
                cout<<endl;
            }
            cout<<"***"<<endl;
        }
        cout<<"---"<<endl;
    paper.clear();
}

}