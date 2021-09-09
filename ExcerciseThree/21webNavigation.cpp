#include<string>
#include<vector>
#include<map>
#include<algorithm>
#include<functional>
#include<stack>
#include<iostream>
using namespace std;

stack<string>fdStack;
stack<string>backStack;

void back(string& currUrl)
{
	if(backStack.empty()) {
		cout<<"Ignored"<<endl;return;
	}
	fdStack.push(currUrl);
	currUrl = backStack.top();
	backStack.pop();
	cout<<currUrl<<endl;
}

void forward(string& currUrl)
{
	if(fdStack.empty()){
		cout<<"Ignored"<<endl;return;
	}
	backStack.push(currUrl);
	currUrl = fdStack.top();
	fdStack.pop();
	cout<<currUrl<<endl;
}

void visit(string& currUrl,const string& newUrl)
{
	backStack.push(currUrl);
	while(!fdStack.empty()) fdStack.pop();
	currUrl = newUrl;
	cout<<currUrl<<endl;
}
int main()
{
    string command;
    string currUrl = "http://www.game.org/";
    while(cin>>command && command != "QUIT")
    {
    	if(command == "VISIT")
		{
    		string newUrl;
    		cin>>newUrl;
    		visit(currUrl, newUrl);
    	}
    	else if(command == "FORWARD")
    	{
    		forward(currUrl);}
    	else if(command == "BACK")
		{
    		back(currUrl);
		}
    	else
    	{
    		cout<<"error"<<endl;
		}
	}
}
