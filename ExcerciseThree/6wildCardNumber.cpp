#include<string>
#include<cmath>
#include<iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	string source; string dest;
	while(cin>>source>>dest)
	{
		int result = 0;
		int cnt = 0;
		int size = source.size(); 
		//
		for(int i = 0 ; i < size ; i ++)
		{
			if(source[i] == '?')cnt++;
		}
		//
		for(int i = 0 ;i < size ; i ++)
		{
			if(source[i] == '?')
			{
				cnt --;
				result += ('9' - dest[i] ) * pow(10,cnt);
			}
			else{
				if(source[i] > dest[i])
				{
					result += pow(10,cnt); break;
				}
				else if(source[i] < dest[i])
				{
					break;
				}
				else continue;
			}
		 } 
		 cout<<result<<endl;
	}
}
