#include<iostream>
#include<vector>
#include<map>
#include<string>
using namespace std;

string encryptChar = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
string originChar  = "VWXYZABCDEFGHIJKLMNOPQRSTU";
map<char,char>table;
void make_table()
{
	for(int i = 0 ; i < 26 ; i ++ )
	{
		table[encryptChar[i]] = originChar[i];
	}
	return;
}
void handle(string& code)
{
	for(int i = 0 ; i < code.size() ; i ++)
	{
		if(isalpha(code[i]))
		{
			code[i] = table[code[i]];
		}
	}
	cout<<code<<endl;
}
int main()
{
	string start;
	while(cin>>start && start != "ENDOFINPUT")
	{
		cout<<"1"<<endl;
		string code ;
		getchar();
		cout<<"2"<<endl;
		getline(cin, code);
		cout<<code;
		string end;
		cin>>end;
		handle(code);
	}
	
}










