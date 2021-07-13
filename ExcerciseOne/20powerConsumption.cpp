#include<iostream>
using namespace std;
int main()
{
    int powerCom = 0;
    int n,powerNor,powerPro,powerSlee,timeNor,timePro;
    cin>>n;
    int origin = n;
    int timeMatrix[origin][2];
    cin>>powerNor>>powerPro>>powerSlee>>timeNor>>timePro;
    for(int i = 0 ; i < origin ; i ++ )
        {
            cin>>timeMatrix[i][0]>>timeMatrix[i][1];
        }
    int timeInterval = 0;
    for(int i =  0 ; i < origin - 1 ; i ++)
    {
        powerCom += (timeMatrix[i][1] - timeMatrix[i][0]) * powerNor;
        timeInterval =  (timeMatrix[i+1][0] - timeMatrix[i][1]);
        if(timeInterval >= (timeNor + timePro) )
        {
            powerCom += ( timeNor * powerNor + timePro * powerPro);
            timeInterval -= (timeNor + timePro);
        }
        else if(timeInterval >= timeNor)
        {
            powerCom += ( timeNor * powerNor + (timeInterval - timeNor) * powerPro) ;
            timeInterval = 0;
        }
        else 
        {
            powerCom += timeInterval * powerNor;
            timeInterval = 0;
        }
        if(timeInterval != 0)
        {
            powerCom += (timeInterval * powerSlee);
            timeInterval = 0;
        }
    }
    powerCom += (timeMatrix[origin - 1][1] - timeMatrix[origin - 1][0]) * powerNor;
    cout<<powerCom;
}