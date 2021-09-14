#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<utility>
#include<algorithm>
using namespace std;

bool comp(pair<int, int>a, pair<int,int>b)
{
	return a.first > b.first;
}
class Poly 
{
	public:
		vector< pair<int,int> >data;
		Poly operator *(Poly& b)
		{
			Poly c;
			int sizea = data.size();
			int sizeb = b.data.size();
			//cout<<sizea<<" "<<sizeb<<endl;
			for(int i = sizea - 1 ; i >= 0 ; i --)
			{
				for(int j = sizeb - 1 ; j >= 0 ; j --)
				{
					int e = data[i].first + b.data[j].first;
					int	n = data[i].second * b.data[j].second;
					//cout<<i<<" : "<<j<<" "<<e<<" "<<n<<endl;
					bool flag = true; 
					for(int k = 0 ; k < c.data.size() ; k ++)
					{
						//cout<<k<<"::::::"<<endl;
						if(c.data[k].first == e)
						{
							//cout<<"重复加起来"<<e<<" : "<<endl;
							c.data[k].second+=n;
							flag = false;
							break;
						}
					}
					if(flag){
						c.data.push_back(pair<int,int>(e,n) );
					}
					//cout<<"输入的值"<<e<<" "<<n<<endl;
				}
			}
			sort(c.data.begin(),c.data.end(), comp);
			return c;
		}	
};
int main()
{
	int n = 0;
	while(cin>>n && n)
	{
		vector<int>sta(n,0);
		vector<int>check(n,0);
		for(int i = 0 ; i < n ; i ++) cin>>sta[i];
		for(int i = 0 ; i < n ; i ++) cin>>check[i];
		vector<Poly>duo(n);
		for(int i = 0 ; i < n ; i ++)
		{
			duo[i].data.push_back(make_pair(1,1));
			duo[i].data.push_back(make_pair(0,sta[i]));
		}
		/*for(auto v : duo)
		{
			cout<<"**************"<<endl;
			for(auto m : v.data)
			{
				cout<<m.first<<" "<<m.second<<endl;
			}
			cout<<"*************"<<endl;
		}*/
		Poly c = duo[0];
		for(int i = 1 ; i < n ;i ++)
		{
			c = duo[i] * c ;
			/*cout<<"*************"<<endl;
			cout<<"c :"<<i<<endl;
			for(auto m: c.data){
				cout<<m.first<<" "<<m.second<<endl;
			}
			cout<<"*************"<<endl;*/
		}
		vector<int>real(n + 1 ,0);
		for(int i = 0 ; i < n + 1; i ++)
		{
			real[i] = c.data[i].second;
			//cout<<"real"<<i<<" "<<real[i]<<endl;
		}
		//sort(check.begin(),check.end());
		//sort(real.begin(),real.end());
		bool flag = true;
		for(int i = 0 ; i < n ; i ++)
		{
			if(check[i] != real[i + 1]){
			flag = false;
			}
		}
		/*for(auto v : real){
			cout<<"real:"<<v<<" ";
		}
		cout<<endl;
		for(auto v :check){
			cout<<"check:"<<v<<" ";
		}*/
		if(flag)cout<<"Y"<<endl;
		else cout<<"N"<<endl;
	}
	
	
	return 0;
}
