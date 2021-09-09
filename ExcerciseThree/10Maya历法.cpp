#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<sstream>
using namespace std;

string Haab[19] = {"pop","no","zip","zotz","tzec","xul","yoxkin",
				"mol","chen","yax","zac","ceh","mac","kankin",
						"muan","pax","koyab","cumhu","uayet"};
						
string Tzolkin[20] = {"imix","ik","akbal", "kan", "chicchan", "cimi", "manik", "lamat", "muluk", "ok",
						"chuen", "eb", "ben", "ix", "mem", "cib", "caban", "eznab", "canac", "ahau"}; 
map<string, int>HaabMonth;



void make_table()
{
	for(int i = 0 ; i < 19 ; i ++)
	{
		HaabMonth[Haab[i]] = i ;
	}
}	

										
int transHaab(int year, string month, int day)
{
	int resultDays = year  * 365 + day + 1;
	resultDays += HaabMonth[month] * 20;
	return resultDays;
}


void transTzolkin(int days)	
{
	int year = days / 260 ;
	days %= 260 ;
	if (days == 0) {
		year--; days += 260; 
	} 
	int month = (days - 1 ) % 13;  //
	month = days / 20;  //
	days %= 20;
	if(days == 0)
	{
		month--;days += 20;
	 } 
	days = (days - 1) % 20 ;
	string day = Tzolkin[days];
	cout<<month + 1 <<" "<<day<<" "<<
		year<<endl;	
}

int main()
{
	make_table();
	int n = 0;
	cin>>n;
	while(n--)
	{
		string first; int year;
		cin>>first>>year;
		string month; string day;
		int off = 0;
		for(int i = 0 ; i < first.size() ; i ++)
		{
			if(first[i] != '.')
			{
				day += first[i];
			}
			else {
				off = i;break;
			}
		}
		for(int i = off + 1 ; i < first.size() ; i ++)
		{
			month += first[i];
		}
		stringstream ss;
		ss<<day;
		int dayInt = 0 ;
		ss>>dayInt;
		transTzolkin(transHaab(year, month, dayInt));	
	}
		
} 




