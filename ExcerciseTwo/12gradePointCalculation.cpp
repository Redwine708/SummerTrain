#include<iostream>
#include<string>
#include<vector>
#include<iomanip>
using namespace std;

double getPoint(double grade)
{
    if(grade>=90 && grade <= 100)
        return 4.0;
    else if(grade<=89&& grade >=85)
        return 3.7;
    else if(grade <=84 && grade >=82)
        return 3.3;
    else if(grade>=78 && grade <=81)
        return 3.0;
    else if(grade >=75&& grade<=77)
        return 2.7;
    else if(grade>=72 && grade <=74)
        return 2.3;
    else if(grade>=68&&grade<=71)
        return 2.0;
    else if(grade>=64&&grade <=67)
        return 1.5;
    else if(grade>=60&&grade<=63)
        return 1.0;
    else if(grade <60)
        return 0;
}

int main()
{
    double sumCredit = 0;
    double credit = 0;
    double score = 0;
    double sumPoint = 0;
    int n = 0;
    cin>>n;
    int a[n];
    for(int i = 0 ; i < n ;i  ++)
    {
        cin>>credit;
        sumCredit+=credit;
        a[i] = credit;
    }
    for(int i = 0 ; i < n ; i ++)
    {
        cin>>score;
        sumPoint+= getPoint(score) * a[i];
    }
    cout<<setprecision(2)<<fixed<<sumPoint / sumCredit ;
}