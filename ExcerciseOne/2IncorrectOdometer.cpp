#include<iostream>
//#include<bits/stdc++.h>
#include<sstream>
#include<iostream>
#include<string>
#include<unordered_map>
#include<map>
using namespace std;

int main()
{
	map<char,string>a;
	char originDecimal[10]={'0','1','2','4','5','6','7','9'};
	string transOct[10]={"0","1","2","3","4","5","6","7"};
	for(int i=0;i<8;i++)
	{
		a[originDecimal[i]]=transOct[i];
	}
	int T;
	cin>>T;getchar();
	int n;
	string s,ss;
	for(int i=0;i<T;i++)
	{
		cin>>s;
		n=s.length();
		ss.clear();
		for(int j=0;j<n;j++)
		{
			ss=ss+a[s[j]];
		}

		stringstream sss;
		int m;

		sss<<oct<<ss;
		sss>>m;
		cout<<m<<endl;
	}
	return 0;
} 


// int main()
// {
//     stringstream ss;
//     /*trans decimal to oct*/
//     int decimal = 12;
//     ss<<oct<<decimal;
//     cout<<ss.str();
//     /*trans oc to decimal*/
//     stringstream sss("856");
//     int oct1;
//     ss>>oct>>oct1;
//     cout<<oct1; 
// }