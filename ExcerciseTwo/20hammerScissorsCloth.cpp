#include<iostream>
#include<string>
#include<cmath>
#include<unordered_map>
using namespace std;
enum result { WIN, DRAW, LOSE};
unordered_map<string,result>win;
void make_win()
{
    win["CJ"] = WIN ; win["JB"] = WIN; win["BC"] = WIN;
    win["CC"] = DRAW; win["JJ"] = DRAW; win["BB"] = DRAW;
    win["JC"] = LOSE; win["BJ"] = LOSE; win["CB"] = LOSE;
}
int main()
{
    make_win();
    int n = 0;
    cin>>n;
    string first,second;
    string final;
    int winTimes = 0; int drawTimes = 0; int loseTimes = 0;
    int jC = 0, jJ = 0, jB = 0;
    int yC = 0, yJ = 0, yB = 0;
    while(n--)
    {
        cin>>first>>second;

        // if(first[0] == 'C' )jC++;
        // else if(first[0] == 'J')jJ++;
        // else jB++;

        // if(second[0] == 'C')yC++;
        // else if(second[0] == 'J')yJ++;
        // else yB++;

        final = first + second;
        if(win[final] == WIN)
        {
            winTimes++;
            if(first[0] == 'C' ){jC++;yJ--;}
            else if(first[0] == 'J'){jJ++;yB--;}
            else {jB++; yC--;}
        }
        else if(win[final] == DRAW)
        {
            drawTimes++;
        }
        else 
        {
            loseTimes++;
            if(first[0] == 'J'){jJ--;yC++;}
            else if(first[0] == 'B'){jB--;yJ++;}
            else {jC--;yB++;}
        }
    }
    cout<<winTimes<<" "<<drawTimes<<" "<<loseTimes<<endl
        <<loseTimes<<" "<<drawTimes<<" "<<winTimes<<endl;

    int flag = 1;
    int maxValue1 = max(yC, max(yJ, yB));
    if(yB == maxValue1 && flag){ flag = 0 ; cout<<"B"<<" ";}
    else if(flag && yC == maxValue1){ flag = 0; cout<<"C"<<" ";}
    else cout<<"J"<<" ";

    flag = 1;
    int maxValue2 = max(jC, max(jJ, jB));
    if(jB == maxValue2 && flag){ flag = 0 ; cout<<"B";}
    else if(flag && jC == maxValue2){ flag = 0; cout<<"C";}
    else cout<<"J";   
    
}