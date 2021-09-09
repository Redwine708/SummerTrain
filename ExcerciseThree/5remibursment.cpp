#include<iostream>
#include<string>
#include<map>
#include<vector>
#include<algorithm>
#include<sstream>
#include<iomanip>
using namespace std;
const int TOTALVALUE = 1000;
const int INITEM = 600;

double judge(vector<string>&items)
{
	double sum = 0.0;
	for(auto v : items )
	{
		if(v[0] > 'C' )return 0;
		else{
			string tmp = "";
			for(int i = 2 ; i < v.size() ; i ++)
			{
				tmp += v[i];
			}
			stringstream ss;
			ss<<tmp;
			double price;
			ss>>price;
			if(price > INITEM)return 0;
			else{
				sum += price;
			}
			if(sum > TOTALVALUE)return 0;
		}
	}
	return sum;
}
int main()
{
	ios::sync_with_stdio(false);
	double reLimit = 0.0 ; int invoiceNums = 0;
	while(cin>>reLimit>>invoiceNums && invoiceNums != 0)
	{
		//cout<<"all: "<<reLimit<<" "<<invoiceNums<<endl<<endl;
		vector<double>sums;
		for(int i = 0 ; i < invoiceNums ; i ++)
		{
			int n = 0; cin>>n;
			vector<string>items;
			string item;
			for(int i = 0 ; i < n ; i ++)
			{
				cin>>item; items.push_back(item);
				//cout<<"item"<<i + 1 <<" "<<item<<endl;
			}
			double sum = judge(items);
			if(sum != 0)
			{
				sums.push_back(sum);
			}
		}
		sort(sums.begin(), sums.end(), greater<int>());
		double result = 0.0;
		for(int i = 0 ; i < sums.size() ; i ++)
		{
			if(sums[i] <= reLimit)
			{
				result  += sums[i];
				reLimit -= sums[i];
			}
		}
		cout<<fixed<<setprecision(2)<<result<<endl;
	}
	return 0;
}
