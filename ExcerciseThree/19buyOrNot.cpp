#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
    string shopKeeper;
    string desired;
    while(cin>>shopKeeper>>desired)
    {
        int count = 0 ;
        int shopSize = shopKeeper.size();
        int desiredSize = desired.size();
        for(int i = 0 ; i < desiredSize ; i ++)
        {
            //find it
            if(find(shopKeeper.begin(), shopKeeper.end(), desired[i] ) != shopKeeper.end())
            {
                auto v = find(shopKeeper.begin(), shopKeeper.end(), desired[i] );
                shopKeeper.erase(v);
                count++;
            }
        }
        if(count == desiredSize)
        {
            cout<<"Yes"<<" "<<shopSize - count<<endl;
        }
        else {
            cout<<"No"<<" "<<desiredSize - count<<endl;
        }
    }

}