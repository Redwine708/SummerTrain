#include<iostream>
#include<string>
#include<vector>
using namespace std;


void handle(string& source)
{
	int abCnt = 0; int baCnt = 0 ;
	int size = source.size();
	for(int i = 0 ; i <= size - 2 ; i ++)
	{
		string tmp = source.substr(i,2);
		if(tmp == "ab")abCnt ++;
		else if(tmp == "ba")baCnt ++;
	}
	cout<<abCnt - baCnt<<endl;
}
int main()
{
	ios::sync_with_stdio(false);
	int nums = 0;
	while(cin>>nums && nums != 0)
	{
		string source;
		cin>>source;
		handle(source);
	}
	return 0;
}
