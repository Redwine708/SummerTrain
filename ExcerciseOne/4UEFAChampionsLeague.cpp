#include<iostream>
#include<string>
#include<vector>
#include<sstream>
#include<algorithm>
using namespace std;

struct Team
{
    string name;
    int credit;
    int goalDifference;
    
    Team()
    {
        credit = 0; goalDifference = 0;
        name = "";
    }
};
const int teamNums = 12;

bool compare(Team first, Team second)
{
    if(first.credit != second.credit)
    {
        return first.credit > second.credit;
    }
    else return first.goalDifference > second.goalDifference;
}

void recodeData(vector<Team>& allTeam,
    string firstTeam,string secondTeam,int matchResult, int firstTeamScores,
                    int secondTeamScores)
{
    if(matchResult > 0 )
        {

        for(int i = 0 ; i < teamNums ; i ++)
        {
            if(allTeam[i].name == firstTeam)
            {
                allTeam[i].credit += 3;
                allTeam[i].goalDifference += firstTeamScores -  secondTeamScores;
            } 
            if(allTeam[i].name == secondTeam)
            {
                allTeam[i].credit += 0;
                allTeam[i].goalDifference += secondTeamScores - firstTeamScores;
        
            }
        }

        }
        else if(matchResult == 0)
        {
        for(int i = 0 ; i < teamNums ; i ++)
        {
            if(allTeam[i].name == firstTeam)
            {
                allTeam[i].credit += 1;
                
            } 
            if(allTeam[i].name == secondTeam)
            {
                allTeam[i].credit += 1;
                
            }
        } 
        }
        else 
        {
            for(int i = 0 ; i < teamNums ; i ++)
        {
            if(allTeam[i].name == firstTeam)
            {
                allTeam[i].credit += 0;
                allTeam[i].goalDifference += firstTeamScores -  secondTeamScores;
            
            } 
            if(allTeam[i].name == secondTeam)
            {
                allTeam[i].credit += 3;
                allTeam[i].goalDifference += secondTeamScores - firstTeamScores;
            
            }
        }
        }
}

int  getData(string& goalData, int indexOff1,const string text)
{
    int indexOff2 = 0;
    for(int i = indexOff1 ; i < text.size() ; i ++)
        {
            if(text[i] != ' ')
            {
                goalData += text[i];
            }
            else
            {
                indexOff2 = i;break;
            }
        }
    return indexOff2;
}
int transInt(string dest)
{
    stringstream ss;
    int goal = 0;
    ss<<dest;
    ss>>goal;
    return goal;
}

int main()
{
    int n = 0;
    cin>>n;
    getchar();
    string text;
    while(n--)
    {
        int origin = teamNums;
        vector<Team> allTeam;
        while(origin--){
           
            string fTeamName;string sTeamName;
            string fTeamGoal; string sTeamGoal;
            getline(cin,text);
            int indexOff = 0;
            int size = text.size();
            indexOff = getData(fTeamName,indexOff,text);
            indexOff = getData(fTeamGoal,++indexOff,text);
            indexOff = getData(sTeamGoal,indexOff += 5,text);
            indexOff = getData(sTeamName,++indexOff,text);
            //if(indexOff != 0)exit(-1);
            //cout<<indexOff;
            int fGoal = transInt(fTeamGoal);
            int sGoal = transInt(sTeamGoal);
            bool flag1 = true; bool flag2 = true;
            if(allTeam.empty())
            {
                Team temp;
                temp.name = fTeamName;
                allTeam.push_back(temp);
                temp.name = sTeamName;
                allTeam.push_back(temp);
            }
            else
            {
                
                for(int i = 0; i < teamNums ; i ++)
                {
                    if(allTeam[i].name == fTeamName)
                    {
                        flag1 = false;
                        continue;
                    }
                    if(allTeam[i].name == sTeamName)
                    {
                        flag2 = false;
                        continue;
                    }
                }
                if(flag1)
                {
                    Team temp;
                    temp.name = fTeamName;
                    allTeam.push_back(temp);
                }
                if(flag2){
                    Team temp;
                    temp.name = sTeamName;
                    allTeam.push_back(temp);
                }
            }
            recodeData(allTeam,fTeamName,sTeamName,fGoal - sGoal, fGoal, sGoal);
        }
        sort(allTeam.begin(), allTeam.end(),compare);
        cout<<allTeam[0].name<<" "<<allTeam[1].name<<endl;
        allTeam.clear();
    }
}
