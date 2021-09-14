#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

struct Player{
	int score;
	int rank;
	int pos;
	Player(){
		score = rank = pos = 0;
	}
};

bool comp1(const Player a,const Player b)
{
	return a.pos < b.pos;
}
bool comp2(const Player a,const Player b)
{
	return a.score > b.score;
}
int main()
{
	ios::sync_with_stdio(false);
	int num = 0;
	while(cin>>num && num > 0)
	{
		vector<Player>players(num);
		for(int i = 0 ; i < num ; i ++)
		{
			cin>>players[i].score;
			players[i].pos = i+1;
		}
		sort(players.begin(), players.end(), comp2);
//		for(auto v: players)
//		{
//			cout<<v.score<<" "<<v.pos<<" "<<v.rank<<endl;
//		}
//		cout<<endl;
		int rank = 1;
		players[0].rank = 1;
		for(int i = 1 ; i < num ; i ++)
		{
			if(players[i].score == players[i-1].score){
				players[i].rank = rank;
			//	cout<<"rank: "<<rank<<" "<<endl;
			}
			else{
				++rank;
				players[i].rank = rank;
			//	cout<<"trank: "<<rank<<" "<<endl;
			}
		}
		sort(players.begin(), players.end(), comp1);
		for(auto v: players)
		{
			cout<<v.rank<<" ";
		}
		cout<<endl;
	}
	
	return 0; 
} 
