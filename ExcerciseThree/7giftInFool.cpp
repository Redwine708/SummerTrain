#include<iostream>
#include<string>
#include<stack>
using namespace std;

int main()
{
	string source;
	while(cin>>source){
		stack<char>bracket;
		for(int i = 0 ; i < source.size() ; i ++)
		{
			if(source[i] == '(')bracket.push('(');
			else if(source[i] == ')')bracket.pop();
			else break;
		}
		cout<<bracket.size()<<endl;
	}
}
