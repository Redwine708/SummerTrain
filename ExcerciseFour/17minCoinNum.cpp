#include<iostream>
#include<string>
#include<vector>
using namespace std;

int sa [5] = {1,5,10,20,100};
int main()
{
	int num = 0;
	while(cin>>num)
	{
		int cnt = 0;
		for(int i = 4 ;i  >=0 ; i --)
		{
			cnt += num / sa[i];
			num %= sa[i];
		}
		cout<<cnt<<endl;
	}	
	
} 
