#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;

string five[5]= {"12345", "23456", "34567", "45678", "56789"};
void compare(string& yourCards, string& otherCards);
void handle(string& yourCards){
	sort(yourCards.begin(), yourCards.end(), less<int>());
}

int main()
{
	string yourCards;
	cin>>yourCards;
	handle(yourCards);
	string otherCards;
    //cout<<yourCards<<" "<<yourCards.size()<<endl;
	while(cin>>otherCards)
	{
		compare(yourCards, otherCards);		
	}	
	return 0;
}
void compare(string& yourCards, string& otherCards){
	int subSize = otherCards.size();
	vector<string>results;
	string result;
	if(subSize != 5){
	if(int(yourCards.size() - subSize) >= 0){
	for(int i = 0 ; i<= yourCards.size() - subSize ; i ++)
	{
		//cout<<"adfadf"<<endl;
		result = yourCards.substr(i, subSize);
		//cout<<"result: "<<result<<" ";
		int count = 1;
		for(int i = 0 ; i < result.size() - 1 ; i ++)
		{
			if( result[i] == result[i+1] )count ++;
		}
		
		if(count == subSize && result > otherCards)
		{
			if( find(results.begin(), results.end(), result) == results.end() )
				results.push_back(result);
		}
	}
	}
	}
	else{
		for(int i = 0 ; i < 5 ; i ++)
		{
			result = five[i];
			int count = 0;
			vector<int>haveFind(5,0);
			for(int j = 0 ; j < 5 ; j ++)
			{
				if(haveFind[j] == 0 &&find(yourCards.begin(), yourCards.end(), result[j]) != yourCards.end())
				{
					haveFind[j] = 1;
					count++;
				}
			}
			if(count == 5 && result > otherCards)results.push_back(result);
		}
	}
	if(results.size() == 0) cout<<"NO"<<endl;
	else{
		cout<<"YES"<<" ";
		for(int i = 0 ; i< results.size() ; i++)
		{
			cout<<results[i]<<" ";
		}
		cout<<endl;
	}
}

















