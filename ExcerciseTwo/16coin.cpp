#include<iostream>
const int MAXDAYS = 10001;
using namespace std;

long long int table[MAXDAYS];
void make_table()
{
    long long int currDays = 1;
    long long int sumDays = 1 ;
    long long int index = 1;
    long long int sumCoin = 1;
    table[1] = 1;
    while(sumDays <= MAXDAYS )
    {
        currDays++;
        for(long long int i = index + 1 ; i < index + currDays + 1; i ++)
        {
            sumCoin += currDays;
            table[i] = sumCoin;
        }
        sumDays += currDays;
        index += currDays;
    }
}
int main()
{
    make_table();
    int days = 0;
    while(cin>>days)
    {
        cout<<days<<" "<<table[days]<<endl;
    }
}