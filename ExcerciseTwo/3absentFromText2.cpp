#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
string name[20000];
int main()
{
    int n;
    while (cin >> n)//总体思路就是，只出现一次名字的同学缺考！！ 
    {
        if (n==0)
            return 0;
        for(int i=0;i<2*n-1;i++)
        {
            cin >> name[i];
        }
        sort(name,name+2*n-1); //对所有名字排序（会按照字典序排序） 
        for(int i=0;i<2*n-1;i+=2)
        {
            if (name[i]!=name[i+1]) //从第一个名字开始，每次循环步长为2
            {							//如果后面的名字与当前名字不同，当前名字就是缺席者的名字
                cout << name[i] << endl;
                break;
            }
        }
    }
}
