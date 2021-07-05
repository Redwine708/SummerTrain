#include<algorithm>
#include<iostream>
using namespace std;
struct String{
    string str;
    int disorder;
    String(string _str)
    {
        str = _str;
        disorder = getDisorder(_str);
    }
    //core
    int getDisorder(string _str)
    {
        int n = _str.size();
        int _disorder = 0;
        for(int i = 0 ; i < n ; i ++)
        for(int j = i + 1 ; j < n ; j ++)
        {
                if( str[i] > _str[j] )_disorder++;
            
        }
        return _disorder;
    }
};
bool compare(String a, String b)
{
    return a.disorder < b.disorder;
}
int main()
{
    int n,m;
    cin>>n>>m;
    string* ptr = new string[m];
    for(int i = 0 ; i < m ; i ++)
    {
        cin>>ptr[i];
    }
    cout<<endl;
    sort(ptr,ptr+m,compare);
    for(int i = 0 ; i < m ; i ++)
    {
        cout<<ptr[i]<<endl;
    }
}
