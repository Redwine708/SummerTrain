// /**
//  * @file stringTraverse.cpp
//  * @author your name (you@domain.com)
//  * @brief 
//  * @version 0.1
//  * @date 2021-07-01
//  * 
//  * @copyright Copyright (c) 2021
//  * 
//  */
#include<string>
#include<stack>
#include<iostream>
using namespace std;
string perform(string a);
int main()
{
    int T = 0;
    cin>>T;
    string a;
    getchar();
    while(T--)
    {
        getline(cin,a);
        // getchar();   
        cout<<perform(a);
        if(T!=0)
        {
            cout<<endl;
        }
    }
}
string perform(string a)
{
    string tmp;
    stack<string>result;
    for(int i = 0 ; i < a.size() ; i ++)
    {
        if(a[i]!=' ')
        {
            tmp+=a[i];
        }
        else 
        {
            result.push(tmp);
            tmp="";
        }
    }
    result.push(tmp);
    tmp="";
    while(!result.empty())
    {
        tmp+=result.top();
        tmp+=" ";
        result.pop();
    }
    tmp.erase(tmp.size() - 1);
    return tmp;
}
// #include <iostream>
// #include <string>
// using namespace std;
 
// int main()
// { 
//     string str, t;
//     while( getline(cin,str) )
//     {
//         int i, j;
//         i = str.size()-1;
//         while( i >= 0 ){
//             j = i;
//             while( i>=0 && str[i]!=' ' )
//                 --i;
//             t = str.substr(i+1, j-i);    
//             if( i < 0 )
//                 break;
                 
//             cout << t << " ";
//             --i; 
//         }
//         cout << t << endl;
//     }
     
//     return 0;
// }