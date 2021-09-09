#include<iostream>
#include<algorithm>
using namespace std;

struct people
{
    int num;//储存输入的顺序，方便在遍历时找到零号感染者
    int pos;//位置
    int v;//速度
};

bool cmp(const people &l,const people &r)
{
    if(l.pos==r.pos)
    {
        return l.v>r.v;
    }
    return l.pos<r.pos;
}

const int N=10000500;
//发现如果N开成10000010会爆内存
//所以N开大点
people p[N];

int main()
{
    int n,s;
    cin>>n>>s;
    for(int i=0;i<n;i++) cin>>p[i].pos;
    for(int i=0;i<n;i++)
    {
        p[i].num=i+1;//初始化编号
        cin>>p[i].v;
    }
    sort(p,p+n,cmp);//排序
    int lmaxv=-1;
    int mid;//存储零号感染者的位置
    for(mid=0;mid<n;mid++)
    {
        if(p[mid].v>lmaxv) lmaxv=p[mid].v;
        //寻找左边速度最大值
        if(p[mid].num==s) break;
        //如果当前选手是零号感染者，退出循环
    }
    int safe=0;//储存未感染人数
    int rminv=1000000;//初始化
    for(int i=mid;i<n;i++)
    {
        if(p[i].v>=lmaxv&&p[i].pos>p[mid].pos)
            safe++;
        //如果右侧选手速度大于左边的最大速度
        //且右边选手的位置大于零号感染者的位置
        if(p[i].v<rminv) rminv=p[i].v;
        //找到右边速度最小值
    }
    for(int i=0;i<mid;i++)
    {
        if(p[i].v<=rminv&&p[i].pos<p[mid].pos)
            safe++;
        //如果左边选手速度小于右边的最小速度
        //且左边选手的位置小于零号感染者的位置
    }
    cout<<n-safe<<endl;
    //输出总人数减去安全人数
    return 0;
}
