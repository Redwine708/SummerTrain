#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
const int MAXN = 101;
int matrix[MAXN][MAXN];
void make_table()
{
	matrix[1][1] = 1;
	int et = MAXN - 1 ;
	for(int i = 1 ; i < MAXN ; i ++)
	{
		if(i != 1){
			matrix[i][1] = matrix[i-1][1] + i - 1;
		}
		int curr = i + 1;
		for(int j = 2 ; j <= et ; j ++ )
		{
			matrix[i][j] = matrix[i][j-1] + curr;
			curr++;  
		}
		et--;
	}
}
void drawMatrix(int n);
int main(){
	make_table();
	int n = 0 ; 
	while(cin>>n && n > 0)
	{
		drawMatrix(n);
	}
	return 0;
}
void drawMatrix(int n)
{
	int et = n;
	for(int i = 1 ; i <= n ; i ++)
	{
		for(int j = 1 ; j <= et ; j ++)
		{
			cout<<matrix[i][j]<<" ";
		}
		et--;
		cout<<endl;
	}
	
}










