//Use vector quantity and determinant to calculate the area of rectangle
#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;

int main()
{
    double x1,y1,x2,y2,x3,y3;
    while(cin>>x1>>y1>>x2>>y2>>x3>>y3)
    {
        if( x1 == 0 && y1 == 0 && 
            x2 == 0 && y2 == 0 &&
            x3 == 0 && y3 == 0 )
            break;
        double detX1 = x2 - x1;
        double detY1 = y2 - y1;
        double detX2 = x3 - x1;
        double detY2 = y3 - y1;
        double a = detX1 * detY2;
        double b = detX2 * detY1;
        cout<<fixed<<setprecision(6)<<abs( a - b ) / 2<<endl;
    }
}