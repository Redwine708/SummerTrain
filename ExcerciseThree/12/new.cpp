#include <iostream>
#include<cstdio>
#include<algorithm>

using namespace std;

struct num{
    int x;//指数
    int p;//系数
};
bool compare(num a,num b){
    if(a.x>b.x)
        return true;
    else
        return false;
}

int main()
{
    struct num s1[1000];
    int _x,_p,_count=0,_x1,_p1;
    while(scanf("%d%d",&_x1,&_p1)){
        if(_x1==0&&_p1==0) break;
        s1[_count].x=_x1;
        s1[_count].p=_p1;
        _count++;
    }
    int itemp=_count;
     while(scanf("%d%d",&_x,&_p)){
        if(_x==0&&_p==0)
            break;
        int flag=1;
        for(int k=0;k<itemp;k++){
            if(s1[k].x==_x){
                s1[k].p+=_p;
                flag=0;
                break;
            }
        }
        if(flag){
            s1[_count].x=_x;
            s1[_count].p=_p;
            _count++;
        }
    }
    sort(s1,s1+_count,compare);
    for(int i=0;i<_count;i++){
        if(s1[i].p==0) continue; //这一步 不同oj可能要求不一样
        if(i==_count-1)
            cout<<s1[i].x<<" "<<s1[i].p;
        else
            cout<<s1[i].x<<" "<<s1[i].p<<endl;
    }
    return 0;
}
