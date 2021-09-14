#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;

struct Student{
	string schoolId;
	int month;
	int day;
	Student(){
		schoolId = "";
		month = day = 0;
	}
}; 

struct compare
{
	bool operator ()(Student a, Student b)
	{
		if(a.month != b.month){
			return a.month < b.month;
		}
		else {
			return a.day < b.day;
		}
	}	
};

int main()
{
	int num = 0;
	cin>>num;
	if(num !=0 ){
	Student* allStudents = new Student [num];
	for(int i = 0 ; i < num ; i ++) 
	{
		cin>>allStudents[i].schoolId;
		cin>>allStudents[i].month;
		cin>>allStudents[i].day;
	}
	stable_sort(allStudents, allStudents + num, compare());
	
//	cout<<endl<<endl;
//	for(int i = 0 ;  i< num ; i ++){
//		cout<<allStudents[i].schoolId<<" "<<allStudents[i].month<<" "<<allStudents[i].day<<endl;
//	}
//	cout<<endl<<endl;
	int month = allStudents[0].month; int day = allStudents[0].day;
	cout<<month<<" "<<day<<" "<<allStudents[0].schoolId;
	for(int i = 1 ; i < num ; i ++)
	{
		if(allStudents[i].month == month &&
			allStudents[i].day == day)
		{
			cout<<" "<<allStudents[i].schoolId;
		}
		else{
			cout<<endl;
			month = allStudents[i].month; day = allStudents[i].day;
			cout<<month<<" "<<day<<" "<<allStudents[i].schoolId;
		}
	}
	/*cout<<endl<<endl;
	for(int i = 0 ;  i< num ; i ++){
		cout<<allStudents[i].schoolId<<" "<<allStudents[i].month<<" "<<allStudents[i].day<<endl;
	}
	cout<<endl<<endl;*/
}
	
	
}
