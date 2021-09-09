#include<iostream>
#include<string>
#include<vector>
using namespace std;


int main()
{
	int size = 0 ;
	cin>>size;
	vector<int>allNums(size, 0);
	for(int i = 0 ; i < size ; i ++)
	{
		cin>>allNums[i];
	}
	vector<int>dp(size, 1);
	int maxV = 1;
	for(int i = 1 ; i < size ; i ++ )
	{
		if( allNums[i] > allNums[i - 1] )
		{
			dp [i] = dp[i - 1] + 1;
		}
		maxV = max(maxV, dp[i]);
	}
	cout<<maxV;
	return 0;	
} 
