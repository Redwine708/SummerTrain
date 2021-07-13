#include<iostream>
#include<algorithm>
#include<string>
#include<sstream>
using namespace std;

int main()
{
    string A;string B;
    string DA; string DB;
    cin>>A>>DA>>B>>DB;
    int Acount = count(A.begin(), A.end(),DA[0]);
    int Bcount = count(B.begin(), B.end(),DB[0]);
    string DA2,DB2;
    for(int i = 0 ; i < Acount ; i ++)
    {
        DA2 += DA;
    }
    for(int i = 0 ; i < Bcount ; i ++)
    {
        DB2 += DB;
    }
    
    stringstream ss;
    long long int t1;
    if(DA2 != ""){
    ss<<DA2;
    ss>>t1;
    }
    else t1 = 0;
    stringstream sss;
    long long int t2;
    if(DB2 != ""){
    sss<<DB2;
    sss>>t2;
    }
    else t2 = 0;
    cout<<t1 + t2;


}