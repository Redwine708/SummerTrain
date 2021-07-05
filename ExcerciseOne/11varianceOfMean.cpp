//This problem just needs to pay attention to round numbers.
#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
/**
 * @brief 
 * problem 11 in cg experiment one
 *  
 */
typedef long long int ll;
int main()
{
    int n = 0 ;
    while(cin>>n)
    {
        if(n == 0 )break;
        //store data
        double * nums = new double [n];
        double sum = 0;
        for(int i = 0; i < n ; i ++)
        {
            cin>>nums[i];
            sum += nums[i];
        }
        double average = sum / n ;
        double sumVariance = 0 ;
        for(int i = 0 ; i < n ; i++)
        {
            sumVariance += pow(abs(nums[i] - average),2);
        }
        cout<< ll(sumVariance / n)  <<endl;
    }
}
