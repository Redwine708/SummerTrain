#include<iostream>
#include<string>
#include<map>
#include<vector>
using namespace std;

int weiFactors[17] = {7 ,9 ,10 ,5 ,8 ,4 ,2 ,1 ,6 ,3 ,7 ,9 ,10 ,5 ,8 ,4 ,2};
map<int,char>checkCode;
char codes[11] = {'1', '0', 'X', '9', '8', '7', '6', '5', '4', '3', '2'};
void make_checkCode()
{
	for(int i = 0 ; i < 11 ; i ++)
	{
		checkCode[i] = codes[i];
	}
}

int calMode(string& id)
{
	make_checkCode();
	int sum = 0;
	int size = 17;
	for(int i = 0 ; i < size ; i++)
	{
		sum += (id[i] - '0') * weiFactors[i];
	}
	return sum % 11;
}
int main()
{
	string id;
	while(cin>>id && id != "-1")
	{
		char real = checkCode[calMode(id)];
		cout<< bool(real == id[17])<<endl;
	} 
	
	return 0;
}
