#include<iostream>
#include<unordered_map>
#include<string>
using namespace std; 

unordered_map<string,string>spellDict;

void findSpell(string spell)
{
	string tmp;
	if(spell[0] == '[')
	{
		for(auto v : spellDict)
		{
			if(v.first == spell) {
				cout<<v.second<<endl;
				return;
			}
		}
		cout<<"what?"<<endl;
		return;
	}
	for(auto v : spellDict)
	{
		if(v.second == spell)
		{
			tmp = v.first;
				tmp.erase(0,1);
				tmp.erase(tmp.size() - 1 , 1);
				cout<<tmp<<endl;
				return;
		}
	}
	cout<<"what?"<<endl;
	return;
}
int main()
{
	string tmp;
	while(getline(cin,tmp) && tmp != "@END@")
	{
		string magicSpell; string spellFunc;
		int off = 0;
		for(int i = 0 ; i < tmp.size() ; i ++)
		{
			if(tmp[i] != ']')
			{
				magicSpell += tmp[i];
				
			}
			else{
				off = i ; break;
			}
		}
		magicSpell += "]";
		tmp.erase(0,off + 2);
		spellFunc = tmp;
		spellDict[magicSpell] = spellFunc;
		/*
		for(auto v : spellDict)
		{
			cout<<v.first<<" "<<v.second<<endl;
		}*/
	}
	int num = 0;
	cin>>num;
	getchar();
	string spell;
	for(int i = 0 ; i < num ; i ++)
	{
		getline(cin,spell);
		findSpell(spell);
	}
}




