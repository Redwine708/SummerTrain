#include<iostream>
#include<string>
#include<vector>
#include<map>
using namespace std;
const int INF = 1000005;

int cal(int money, vector<int>& faceValues)
{
	int cnt = 0;
	int size = faceValues.size();
	for(int i = size - 1 ; i >=0 ; i --)
	{
		int div = money / faceValues[i];
		cnt += div;
		money -= div * faceValues[i];
	}
	return cnt;
}

//int dfs(int money, vector<int>&faceValues, int cnt, int currLayer, int maxLayer)
//{
//	if(money == 0 )return cnt;
//	if(money < 0 ||currLayer == maxLayer)return INF;
//	for(int i = faceValues.size() - 1; i >=0  ; i --)
//	{
//		cnt = min( min( dfs(money, faceValues, cnt, currLayer + 1 , maxLayer), dfs(money - faceValues[i], faceValues,cnt + 1 ,currLayer + 1, maxLayer) ), cnt  );
//	}
//	return cnt;
//}
int main()
{
	int money = 0;
	while(cin>>money && money)
	{
		int nums = 0;
		cin>>nums;
		vector<int>faceValues(nums,0);
		for(int i = 0 ; i < nums ; i ++)
		{
			cin>>faceValues[i];
		}
		int maxLayer = money / faceValues[0];
		int t = cal(money,faceValues);
		//int t = dfs(money,faceValues,INF,1,maxLayer);
		if(t) cout<<t<<endl;
		else cout<<"Impossible"<<endl;
	}
}


