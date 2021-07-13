#include<algorithm>
#include<vector>
#include<string>
#include<iostream>
#include<unordered_map>
using namespace std;
int getScore [10] = { 25,18,15,12,10,8,6,4,2,1 };

bool compare1(pair<string , pair<int , unordered_map<int , int > > >fPerson,
                pair<string , pair<int , unordered_map<int , int > > >sPerson)
{
    if(fPerson.second.first != sPerson.second.first)
        return fPerson.second.first > sPerson.second.first;
    unordered_map<int ,int >::iterator iter1 = fPerson.second.second.begin();
    unordered_map<int , int >::iterator iter2 = sPerson.second.second.begin();
    for(; iter1 != fPerson.second.second.end() && iter2 != sPerson.second.second.end();
                 iter1++,iter2++)
    {
        if( ( *iter1 ) != (*iter2) )return ( *iter1 ) >( *iter2 );
    }
    return true;
}

bool compare2(pair<string , pair<int , unordered_map<int , int > > >fPerson,
                pair<string , pair<int , unordered_map<int , int > > >sPerson)
{
    if(fPerson.second.second[0] != sPerson.second.second[0] )
        return fPerson.second.second[0] > sPerson.second.second[0];
    if(fPerson.second.first != sPerson.second.first)
        return fPerson.second.first > sPerson.second.first;
    unordered_map<int ,int >::iterator iter1 = fPerson.second.second.begin();
    unordered_map<int , int >::iterator iter2 = sPerson.second.second.begin();
    for( ; iter1 != fPerson.second.second.end() && iter2 != sPerson.second.second.end() ;
                 iter1++,iter2++)
    {
        if( ( *iter1 ) != (*iter2) )return ( *iter1 ) >( *iter2 );
    }
    return true;
    
    
}

int main()
{
    //string store the name
    //pair.first store the score
    //pair.second store the ranking
    unordered_map< string , pair<int , unordered_map<int , int > > > person ;
    vector< pair<string , pair<int , unordered_map<int , int > > > >sortPerson ;
    int n = 0 ; 
    cin>>n;
    while(n --)
    {
        int rank = 0;int personNums; string name;
        cin>>personNums; 
        while(personNums -- )
        {
            cin>>name;
            person[name].first += getScore[rank];
            person[name].second[rank] ++ ;
            rank ++ ; 
        } 
        rank = 0 ;
    }
    for(auto& v : person)
    {
        sortPerson.push_back(v);
    }
    sort( sortPerson.begin(), sortPerson.end(), compare1 );
    cout<<sortPerson[0].first<<endl;
    sort( sortPerson.begin(), sortPerson.end(),compare2 );
    cout<<sortPerson[0].first;

    


}