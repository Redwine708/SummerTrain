#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main()
{
	vector<int>allNums;
	int num;
	while(cin>>num){allNums.push_back(num);}
	sort(allNums.begin(), allNums.end(), less<int>() );
	int firstNumPos = 0;
	for(int i = 0 ; i < allNums.size() ; i ++)
	{
		if(allNums[i] != 0){
			firstNumPos = i ; break; 
		}
	}
	if(firstNumPos != 0)
	{
		swap(allNums[0], allNums[firstNumPos]);
	}
	for(auto v : allNums){
		cout<<v;
	}
	
	return 0;	
} 
