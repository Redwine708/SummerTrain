#include<iostream>
#include<vector>
#include<string>
using namespace std;

int main()
{
	string origin;
	while(cin>>origin)
	{
		int originSize = origin.size();
		vector<int>prea(originSize, 0);
		vector<int>preb(originSize, 0);
		if(origin[0] == 'a')
		{
			prea[0] = 1; preb[0] = 0;
		}
		else{
			prea[0] = 0; preb[0] = 1;
		}
		for(int i = 1 ; i < originSize ; i ++)
		{
			if(origin[i] == 'a')
			{
				prea[i] = prea[i - 1] + 1;
				preb[i] = preb[i - 1];
			}
			else{
				preb[i] = preb[i-1] + 1;
				prea[i] = prea[i-1];
			}
		}
		int maxLength = 1;
		for(int i = 0 ; i < originSize ; i ++)
		{
			/*
			for(int j = i ; j < originSize ; j ++)
			{
				int length = prea[i] + preb[j] - prea[i-1] + prea[originSize - 1] - prea[j - 1];
				maxLength = max(length, maxLength); 
			}*/
			
			for(int j = 0 ; j < i ; j ++)
			{
				int length = prea[j] + preb[i] - preb[j - 1] + prea[originSize - 1] - prea[i - 1];
				maxLength = max(length, maxLength);	
			}
		}
		cout<<maxLength<<endl;
	}
	
	return 0;
} 

