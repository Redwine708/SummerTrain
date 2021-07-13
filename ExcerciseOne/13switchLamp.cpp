#include<iostream>
#include<string>
using namespace std;
//the maxsize of the matrix
const int MAXSIZE = 10008;

int judge(int** numMatrix,int n , int m);
int main()
{
    //column      row
    int n = 0 ; int m = 0;
    cin>>n>>m;
    string *str = new string[n];
    int** numMatrix = new int* [n];
    for(int i = 0 ; i < n ; i ++)
    {
        numMatrix[i] = new int [m];
    }
    for(int i = 0 ; i < n ; i ++)
    {
        cin>>str[i];
    }
    for(int i = 0 ; i < n ; i ++)
    {
        for(int j = 0 ; j < m ; j++)
        {
            numMatrix[i][j] = str[i][j] - '0';
        }
    }
    if(judge(numMatrix,n,m))cout<<"YES";
    else cout<<"NO";
}

int judge(int ** numMatrix,int n , int m)
{
    int flag = false; 
    int mark = true;
    int  *sum  = new int[m];
    fill( sum, sum+m, 0 );
    for(int i = 0 ; i < n ; i ++ )
    {
        for(int j = 0 ; j < n ; j ++)
        {
            if(i == j)continue;
            for(int k = 0 ; k < m ; k ++)
            {
                sum[k] += numMatrix[j][k];
            }
        }
        for(int x = 0 ; x < m ; x ++ )
        {
            if(sum[x] == 0){
                flag = false;
                mark = false;
                break;
            }
        }
        if(mark == true)flag = true;
        mark = true;
        fill( sum, sum+m, 0 );
    }
    //delete sum;
    return flag;
}
