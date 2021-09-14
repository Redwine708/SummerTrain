#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<iomanip>
#include<algorithm>
using namespace std;
 
string dayOfWeek[7] = { "Saturday", "Sunday","Monday", "Tuesday", "Wednesday", "Thursday", "Friday" };
int monthDays[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};  //闰年的二月有变化 
const string START = "Saturday";   //2000年1月1日是星期六
 
bool isLeapYear(int year)
{
	return (year % 400 == 0) || (year % 100 != 0 && year % 4 == 0);
}

void calTime(int days)
{
	int year = 2000; int month = 0 ; int day = 1; 
	for(int currDays = 1 ; currDays <= days ; currDays ++)
	{
		if(isLeapYear(year))monthDays[1] = 29;
		else monthDays[1] = 28;
		day++;
		if(day == monthDays[month] + 1)
		{
			month++; day = 1;
		}
		if( month == 12 ){
			year++; month = 0;
		}
	}
	
	cout<<year<<"-";
	cout<<setw(2)<<setfill('0')<<month + 1<<"-";
	cout<<setw(2)<<setfill('0')<<day<<" "<<dayOfWeek[days % 7 ]<<endl;
}

int main()
{
	int n = 0;
	while(cin>>n && n != -1)
	{
		calTime(n);
	}
}

