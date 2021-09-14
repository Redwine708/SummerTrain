#include<iostream>
#include<string>
#include<vector>
using namespace std;

int calReversNums(vector<int>& nums)
{
	int cnt = 0 ; int n = nums.size();
	for(int i = 0 ; i < n ;  i ++ )
	{
		for(int j = i + 1 ; j < n ; j ++)
		{
			if(nums[i] > nums[j])cnt++;
		}
	}
	return cnt;
}
int main()
{
	int n = 0 ;
	while(cin>>n && n != 0)
	{
		vector<int>nums(n,0);
		for(int i = 0 ;  i < n ; i ++)
		{
			cin>>nums[i];
		}
		cout<<calReversNums(nums)<<endl;
	}
	return 0;	
} 
