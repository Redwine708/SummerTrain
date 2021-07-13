#include<iostream>
#include<string>
#include<map>
#include<vector>
#include<unordered_map>
using namespace std;

map<string,int>hash1;
vector<string>hash2;
int main()
{
    // string str[7] = { "中", "华", "人", "民", "共", "和", "国"};
    // for (int i = 0; i < 7; i++)
	// cout << str[i];
    int n = 0; 
    while(cin>>n)
    {
        if(n == 0 )break;
        int size = 2 * n - 1;
        string text;
        while(size--)
        {
            cin>>text;  
            //1cout<<text;
            //cout<<text[0]<<endl;
          
                hash1[text] ++ ;
            
                //hash2.push_back(text);
        
        }
        // for(int i = 0 ;  i < hash2.size() ; i ++)
        // {
        //     cout<<hash2[i]<<endl;
        // }
        for(auto& v : hash1)
        {
            if(v.second%2 == 1){cout<<v.first<<endl;break;}
        }
        hash1.clear();
        
    }
}







