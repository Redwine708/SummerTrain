#include <iostream>
#include <algorithm>
#include <string>
#include <sstream>
#include <vector>
#include <map>
using namespace std;
const int MAXSIZE = 2002;
int matrix[MAXSIZE][MAXSIZE];

bool isCheckBoard(int xLeft, int xRight,int yLeft, int yRight )
{
    for(int i = xLeft ; i <= xRight ; i ++)
    {
        for(int j = yLeft ; j <= yRight  ; j ++)
        {
            //black
            if( ( i - xLeft + 1 + j - yLeft + 1 ) % 2 == 0 )
            {
                if(matrix[i][j] != 1)return false;
            }
            else{
                if(matrix[i][j] != 0)return false;
            }
        }
    }
    return true;
}

int main()
{
    int n = 0;
    cin>>n;
    //store data
    vector<string>table;
    for(int i  = 0 ; i < n ; i ++)
    {
        string tmp;
        cin>>tmp;
        table.push_back(tmp);
    }
    
    for(int i = 1 ; i <= n ; i ++)
    {
        for(int j = 1 ; j <= n ; j ++)
        {
            matrix[i][j] = table[i - 1 ][ j - 1] - '0'; 
        }
    }
    int nOrigin = n;
    while( nOrigin )
    {
        int count = 0;
        int yLeft = 1; int yRight = yLeft + nOrigin - 1;
        while( yRight <= n )
        {
            int xLeft = 1; int xRight = xLeft + nOrigin - 1;
            while(xRight <=n)
            {
                if(isCheckBoard(xLeft,xRight,yLeft,yRight) )
                {
                    count++;
                }
                xLeft++;xRight++;
            }
            yRight++ ; yLeft ++;
        }
        if(count != 0){
            cout<<nOrigin<<" "<<count;
            break;
        }
        nOrigin--;
    }


    
}