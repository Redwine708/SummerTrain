//
//#include <bits/stdc++.h>
//using namespace std;
//int a[101], b[101]; //0��Ϣ 1���� 2���� 
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

//f[i][j]��ʾ����i��Ϊֹ�ҵ�i������j����С��Ϣ����

int main()
{
	//����
    cin>>n;
    
    //��ʼ��ÿ�ַ���Ϊ������
	memset(f,inf,sizeof f);
	
	//���ֻ��0�죬������ô����û����Ϣ
    f[0][0]=f[0][1]=f[0][2]=0;
    
    //dp
    int x;
    for(int i=1;i<=n;i++)//�������±�-1�Ĳ������������Ǵ�1��ʼ
    {
        cin>>x;//�����������ʲô
        f[i][0]=min(f[i-1][0],min(f[i-1][1],f[i-1][2]))+1;//������Ϣ�Ļ��������ʲô�����ԣ���������ض����ڣ�����Ҫ�ж�
        if(x==1||x==3)//���������Ա��
            f[i][1]=min(f[i-1][0],f[i-1][2]);//���������Ϣ�ͽ���
        if(x==2||x==3)//���������Խ���
            f[i][2]=min(f[i-1][0],f[i-1][1]);//���������Ϣ�ͱ��
    }
	
	//���
	//��n�����ǿ��������������������е���Сֵ
    cout<<min(f[n][0],min(f[n][1],f[n][2]))<<endl;
    system("pause");
    return 0;
}
