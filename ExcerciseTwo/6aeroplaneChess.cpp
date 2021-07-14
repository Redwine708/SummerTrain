#include<iostream>
#include<algorithm>
#include<string>
#include<sstream>
#include<vector>
#include<map>
#include<set>
using namespace std;

long long int getPoint(long long int A,long long  int B,long long int C)
{
    return ( ( A * C + B ) % 6 + 1 ) ;
}

int main()
{
    long long int N,A,B,C;
    while(cin>>N>>A>>B>>C)
    {
        vector<long long int>checkBoard( N , 0 );
        string grid;
        //initialize the checkboard
        for(int i = 0 ; i < N ;i ++)
        {
            cin>>grid;
            //special grid
            if(grid != "N" )
            {
                checkBoard[i] =  ( grid[1] - '0' );
            }
        }
        long long int currPosLe = 0; long long int currPosYue = 0;
        long long int currStatus = 0;
        while(currPosLe != ( N - 1 ) && currPosYue != ( N - 1 ) ) 
        {
            if(currStatus%2 == 0)
            {
                C = getPoint(A,B,C);
                if(currPosLe + C <= N - 1)
                {
                    currPosLe += C;
                }
                else{
                    currPosLe = N - 1 - ( C - ( N - 1 - currPosLe) );
                }
                if(checkBoard[currPosLe] != 0)
                {
                    currPosLe = checkBoard[currPosLe];
                }
                //return origin
                if(currPosLe == currPosYue)
                {
                    currPosYue = 0;
                }
                currStatus++;
            }
            else if(currStatus%2 == 1)
            {
                C = getPoint(A,B,C);
                if(currPosYue + C <= N - 1)
                {
                    currPosYue += C;
                }
                else{
                    currPosYue = N - 1 - ( C - ( N - 1 - currPosYue) );
                }
                if(checkBoard[currPosYue] != 0)
                {
                    currPosYue = checkBoard[currPosYue];
                }
                if(currPosLe == currPosYue)
                {
                    currPosLe = 0;
                }
                currStatus++;
            }
        }
        if(currPosLe == N - 1)
            cout<<"Lele"<<endl;
        else 
            cout<<"Yueyue"<<endl;

    }
}