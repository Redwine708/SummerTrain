#include<iostream>
#include<string>
#include<map>
using namespace std;

string encrtptString = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
string originString  = "VWXYZABCDEFGHIJKLMNOPQRSTU"; 
map<char,char>table;
void make_table()
{
	for(int i = 0 ; i < 26 ; i ++)
	{
		table[encrtptString[i]] = originString[i];
	}
	return;
}
void handle(string& code)
{
	for(int i = 0 ; i < code.size() ; i ++)
	{
		if(code[i] >= 'A' && code[i] <= 'Z')
		{
			code[i] = table[code[i]];
		}
	}
	cout<<code<<endl;
	
}

int main()
{
	make_table();
	string start;
	while(cin>>start && start != "ENDOFINPUT")
	{
		getchar();
		string code;
		getline(cin,code);
		string end;
		cin>>end;
		handle(code);
	 } 
	
	
	
	
	
}
