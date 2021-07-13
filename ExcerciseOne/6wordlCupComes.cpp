#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

//team
struct Team
{
        string name;
        int credit;
        int goalDifference;
        int score;
        Team()
        {
            credit = 0; goalDifference = 0; score = 0;
            name = "";
        }
};
bool compare(Team first, Team second)
{
    if(first.credit != second.credit)
        return first.credit > second.credit;
    else if(first.goalDifference != second.goalDifference)
        return first.goalDifference > second.goalDifference;
    else return first.score > second.score;
}
bool compare2(Team first, Team second)
{
    return first.name < second.name;
}

void recordData(Team* allTeam, char firstTeam, char secondTeam, int matchResult,
     int teamNums, int firstTeamScores, int secondTeamScores);

int main()
{
    int teamNums;
    cin>>teamNums;
    Team *allTeam = new Team[teamNums];
    string teamName;
    for(int i = 0; i < teamNums ; i ++)
    {
        cin>>teamName;
        allTeam[i].name = teamName;
    } //teamName over
    string resultOfMatch,resultOfMatchSocres;
    for(int i = 0 ; i < ( teamNums * (teamNums - 1) )/ 2; i ++)
    {
        cin>>resultOfMatch>>resultOfMatchSocres;
        char firstTeam = resultOfMatch[0]; char secondTeam = resultOfMatch[2];
        int firstTeamScores =  resultOfMatchSocres[0] - '0';
        int secondTeamScores = resultOfMatchSocres[2] - '0';
        //for(int j = 0 ; j < teamNums ; j ++)
        //{
            recordData(allTeam, firstTeam, secondTeam, firstTeamScores - secondTeamScores, teamNums, firstTeamScores, secondTeamScores );
        //}
    }
    sort(allTeam, allTeam + teamNums, compare);
    sort(allTeam,allTeam+ ( teamNums / 2 ) ,compare2);
    for(int i = 0 ; i < teamNums / 2 ; i ++)
    {
        cout<<allTeam[i].name<<endl;
    }
}
void recordData(Team* allTeam, char firstTeam, char secondTeam, int matchResult,
     int teamNums, int firstTeamScores, int secondTeamScores)
{
    //fist team win
    if(matchResult > 0 )
    {

    for(int i = 0 ; i < teamNums ; i ++)
    {
        if(allTeam[i].name[0] == firstTeam)
        {
            allTeam[i].credit += 3;
            allTeam[i].goalDifference += firstTeamScores -  secondTeamScores;
            allTeam[i].score += firstTeamScores;
        } 
        if(allTeam[i].name[0] == secondTeam)
        {
            allTeam[i].credit += 0;
            allTeam[i].goalDifference += secondTeamScores - firstTeamScores;
            allTeam[i].score += secondTeamScores;
        }
    }

    }
    else if(matchResult == 0)
    {
       for(int i = 0 ; i < teamNums ; i ++)
    {
        if(allTeam[i].name[0] == firstTeam)
        {
            allTeam[i].credit += 1;
            allTeam[i].score += firstTeamScores;
        } 
        if(allTeam[i].name[0] == secondTeam)
        {
            allTeam[i].credit += 1;
            allTeam[i].score += secondTeamScores;
        }
    } 
    }
    else 
    {
        for(int i = 0 ; i < teamNums ; i ++)
    {
        if(allTeam[i].name[0] == firstTeam)
        {
            allTeam[i].credit += 0;
            allTeam[i].goalDifference += firstTeamScores -  secondTeamScores;
            allTeam[i].score += firstTeamScores;
        } 
        if(allTeam[i].name[0] == secondTeam)
        {
            allTeam[i].credit += 3;
            allTeam[i].goalDifference += secondTeamScores - firstTeamScores;
            allTeam[i].score += secondTeamScores;
        }
    }
    }
}