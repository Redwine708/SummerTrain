#include<iostream>
#include<vector>
const int MAXN = 30000;
const int NUMS = 7; 
using namespace std;

bool includeNums(int n)
{
	while(n)
	{
		int tmp = n % 10;
		if(tmp == NUMS)return true;
		n /= 10 ;
	}
	return false;
} 
int main()
{
	int n = 0;
	cin>>n;
	for(int i = 1 ; i <= n ; i ++)
	{
		if( i % NUMS == 0 || includeNums(i) )
		{
			cout<<i<<endl;
		}
	}
	return 0;
}
