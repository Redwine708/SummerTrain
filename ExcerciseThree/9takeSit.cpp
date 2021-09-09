#include<iostream>
#include<algorithm>
#include<vector>
#include<iterator>
using namespace std;


void print(const vector<int>& seat)
{
	ostream_iterator<int> t(cout," ");
	cout<<endl;
	copy(seat.begin(), seat.end(), t);
	cout<<endl;
}
bool takeSeat(vector<int>&seat, int id, int num);
bool releaseSeat(vector<int>&seat, int id);
int main()
{
	ios::sync_with_stdio(false);
	int n,m;
	cin>>n>>m;
	vector<int>seat(n * n, 0);
	int k;
	cin>>k;
	//print(seat);
	for(int i = 0 ; i < k ; i ++ )
	{
		bool flag = true;
		string command;
		cin>>command;
		if(command == "in")
		{
			int id,num; cin>>id>>num;
			flag = takeSeat(seat,id,num);
		 }
		 else{
		 	int id;
			 cin>>id; 
			 flag = releaseSeat(seat,id);
		 } 
		 if(flag)cout<<"yes"<<endl;
		 else cout<<"no"<<endl;
		 //print(seat);
	}
	
}
bool takeSeat(vector<int>&seat, int id, int num)
{
	int size = seat.size();
	for(int i = 0 ; i < size ; i ++)
	{
		
		if(seat[i] == id )return false;
		
		if(seat[i] == 0)
		{
			int count = 1;
			int j = i;
			while( (++j) < size && seat[j] == 0){count++;}
			//cout<<"count:"<<count<<endl;
			if(count >= num)
			{
				int t = 0;
				while(t < num){
					seat[i + (t ++) ] = id;
				}
				return true;
			}
		}
	}
	return false;	
} 
bool releaseSeat(vector<int>&seat, int id)
{
	int size = seat.size();
	bool flag = false;
	for(int i = 0 ; i < size ; i ++)
	{
		if(seat[i] == id){
			seat[i] = 0;
			flag = true;
		}	
	}
	return flag;
}
