#include<iostream>
#include<vector>
#include<string>
using namespace std;

int main()
{
	int num = 0;
	cin>>num;
	vector<vector<int>>tower(num,vector<int>(num,0));
	vector<vector<int>>maxPath(num,vector<int>(num,0));
	int value = 0; 
	for(int i = 0 ; i < num ; i ++)
	{
		for(int j = 0 ; j <= i ; j ++)
		{
			cin>>value;
			maxPath[i][j] = tower[i][j] = value;
		}
	}
//	for(auto v : tower)
//	{
//		for(auto m : v){
//			cout<<m<<" ";
//		}
//		cout<<endl;
//	}
	for(int i = num - 2 ; i >= 0 ; i --)
	{
		for(int j = 0 ; j <= i ; j ++)
		{
			if(maxPath[i + 1][j] > maxPath[i + 1][j + 1])
			{
				maxPath[i][j] += maxPath[i+1][j];
			}
			else{
				maxPath[i][j] += maxPath[i+1][j+1];
			}
		}
	}
//	for(auto v : maxPath)
//	{
//		for(auto m : v){
//			cout<<m<<" ";
//		}
//		cout<<endl;
//	}
	cout<<maxPath[0][0]<<endl;
	cout<<tower[0][0]<<" ";
	int j = 0;
	for(int i = 1 ; i < num ; i ++)
	{
		if(maxPath[i][j] > maxPath[i][j+1])
		{
			cout<<tower[i][j]<<" ";
		}
		else{
			cout<<tower[i][j+1]<<" ";
			j++; 
		}
	}
}
