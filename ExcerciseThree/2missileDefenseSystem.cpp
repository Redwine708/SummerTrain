#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

int main()
{
	int missileNum = 0;
	while(cin>>missileNum )
	{
	vector<int>missile(missileNum, 0);
	for(int i = 0  ; i< missileNum ; i ++)
	{
		cin>>missile[i];
	}
	vector<int>dp(missileNum,0);
	int maxSize = 0;
	for(int i = 0 ; i < missileNum; i++)
	{
		dp[i] = 1;
		for(int j = 0 ; j < i ; j ++)
		{
			if(missile[j] >= missile[i])
			{
				dp[i] = max(dp[i], dp[j] + 1);
			}
		}
		maxSize = max(maxSize,dp[i]);
	}
	cout<<maxSize<<endl;
}
}
