#include<string>
#include<vector>
#include<sstream> 
#include<iostream>
using namespace std;
int transint(string tmp)
{
	stringstream ss;
	ss<<tmp;
	int result;
	ss>>result;
	return result;
}
int transKnut(string price)
{
	int offSize = 0;
	string tmp;
	int result = 0;
	for(int i = 0 ; i < price.size() ; i ++)
	{
		if(price[i] !='.')tmp += price[i];
		else{
			offSize = i ;
			break;
		}
	}
	result +=( (transint(tmp)) * 29 * 17  );
	tmp = "";
	for(int i = offSize + 1 ; i < price.size() ;  i ++)
	{
		if(price[i] !='.')tmp += price[i];
		else{
			offSize = i ;
			break;
		}
	}
	result += (transint(tmp) * 29 );
	tmp = "";
	for(int i = offSize + 1 ;  i < price.size() ; i ++)
	{
		tmp += price[i];
	}
	result += transint(tmp);
	return result;
}


void transStandard(int charge)
{
	if(charge < 0 ){
	cout<<"-";
	charge = (-charge);
}
	cout<<charge / (29 * 17)<<".";
	charge %= (29*17);
	cout<<charge / 29 <<".";
	charge %= 29;
	cout<<charge<<endl;
}
int main()
{
	string price; string actuallPay;
	while(cin>>price>>actuallPay)
	{
		int priceTrans = transKnut(price);
		int actuallPayTrans = transKnut(actuallPay);
		int charge = actuallPayTrans - priceTrans;
		transStandard(charge);
	}
	return 0;
}
