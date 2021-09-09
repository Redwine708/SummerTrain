#include <iostream>
#include <algorithm>
#include <string>
#include <sstream>
#include <vector>
#include <map>
using namespace std;

const double MAXTIME = 10000;
enum status{ NORMAL, INFECTED };
vector< pair< pair<double ,double >, status > >people;

bool compare(pair< pair<double ,double >, status > first , pair< pair<double ,double >, status> second)
{
    return first.first.first < second.first.first;
}

int main()
{
    int n = 0 ; int infectPersonIndex = 0;
    cin>>n>>infectPersonIndex;
    vector<double>displacement(n,0);
    vector<double>velocity(n,0);
    for(int i = 0 ; i < n ;i ++)
    {
        cin>>displacement[i];
    }
    for(int i = 0 ;i < n ; i ++)
    {
        cin>>velocity[i];
    }
    for(int i = 0 ; i < n ; i ++)
    {
        people.push_back( make_pair( make_pair( displacement[i],velocity[i]),NORMAL ) );
    }
    //first person who was infected
    int infectedPersonNums = 0;
    people[infectPersonIndex - 1].second = INFECTED;
    double nowTime = 0;
    while(nowTime < MAXTIME)
    {
        for(auto&v : people)
        {
            //update the displacement
            v.first.first += v.first.second * (nowTime != 0) * 0.01 ;
        }
        sort(people.begin(), people.end(), compare);
        for(int i = 1 ; i < n ; i ++)
        {
            if(people[i - 1].second == INFECTED &&
                people[i].first.first == people[i-1].first.first)
            {
                people[i].second = INFECTED;
            }
            if(people[i].second == INFECTED &&
                people[i].first.first == people[i-1].first.first)
            {
                people[i-1].second = INFECTED;
            }
        }
        // for(auto&v :people)
        // {
        //     cout<<v.first.first<<" ";
        // }
        // cout<<endl;
        // for(auto&v:people)
        // {
        //     cout<<v.first.second<<" ";
        // }
        // cout<<endl;
        // for(auto&v:people)
        // {
        //     cout<<v.second<<" ";
        // }
        // cout<<endl;
        // cout<<"****************"<<endl;
        for(auto&v : people)
        {
            if(v.second == INFECTED)infectedPersonNums++;
        }
        if(infectedPersonNums == n)break;
        nowTime+=0.01;
    }
    infectedPersonNums = 0;
    for(auto&v : people)
    {
        if(v.second == INFECTED)infectedPersonNums++;
    }
    cout<<infectedPersonNums;

}


