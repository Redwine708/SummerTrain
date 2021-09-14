//
//#include <bits/stdc++.h>
//using namespace std;
//int a[101], b[101]; //0休息 1竞赛 2健身 
// 
//int plan(int d, int n)
//{
//	if (d==1) {
//		b[0]=a[0]; 
//	}
//	else {
//		plan(d-1, n);
//		if (a[d-1]==3&&(b[d-2]==1||b[d-2]==2)) b[d-1]=3-b[d-2];
//		else if ((a[d-1]==1||a[d-1]==2)&&a[d-1]==b[d-2]) b[d-1]=0;
//		else b[d-1]=a[d-1];
//	}
//	return count(b, b+n, 0);
//}
// 
//int main()
//{
//	int n; cin >> n;
//	for (int i = 0; i < n; i++) cin >> a[i];
//	cout << plan(n,n);
//	return 0;
//}
//
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

const int N=110,inf=0x3f3f3f3f;
int n;
int f[N][3];

//f[i][j]表示到第i天为止且第i天做了j的最小休息天数

int main()
{
	//输入
    cin>>n;
    
    //初始化每种方案为不存在
	memset(f,inf,sizeof f);
	
	//如果只有0天，不管怎么样都没得休息
    f[0][0]=f[0][1]=f[0][2]=0;
    
    //dp
    int x;
    for(int i=1;i<=n;i++)//由于有下标-1的操作，所以我们从1开始
    {
        cin>>x;//输入今天做了什么
        f[i][0]=min(f[i-1][0],min(f[i-1][1],f[i-1][2]))+1;//今天休息的话，昨天干什么都可以，这种情况必定存在，不需要判断
        if(x==1||x==3)//如果今天可以编程
            f[i][1]=min(f[i-1][0],f[i-1][2]);//昨天可以休息和健身
        if(x==2||x==3)//如果今天可以健身
            f[i][2]=min(f[i-1][0],f[i-1][1]);//昨天可以休息和编程
    }
	
	//输出
	//第n天我们可以有三种情况，输出其中的最小值
    cout<<min(f[n][0],min(f[n][1],f[n][2]))<<endl;
    system("pause");
    return 0;
}
