//23.字符串压缩
#include <iostream>
#include <string>

using namespace std;

int main()
{
    int n, a, b;//字符串长度、a、b
    string str, sa = "", sb = "";//字符串、t(1)t(2)……t(i-1)、t(i)
    int sumMin = 0;//所用最少钱币数
    cin >> n >> a >> b;
    cin >> str;

    sumMin += a;//第一个字母一定要用a个钱币
    for (int k = 1; k < n; k++)
    {
        bool flag = false;//t(i)是否能作为t(1)t(2)……t(i-1)的子串
        sa = str.substr(0, k);//获取sa：t(1)t(2)……t(i-1)
        for (int j = 1; j < n; j++)
        {
            sb = str.substr(k, n - j);//sb：t(i)从最长的可能情况开始
            if (sa.find(sb) != string::npos)//sb是sa的子串
            {
                int len = sb.length();
                if (len >= b / a)//保证将sb作为一个字符串所用钱币比拆成单个所用钱币少
                {
                    sumMin += b;
                    flag = true;
                    k += (n - j - 1);//t(1)t(2)……t(i-1)的长度加上t(i)的长度，k++之后还会+1，所以在这里提前-1
                    break;
                }
            }
        }
        if (flag == false)
        {
            sumMin += a;
        }
    }
    cout << sumMin << endl;
    return 0;
}