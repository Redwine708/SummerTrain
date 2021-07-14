#include<iostream>
#include<vector>
const int MAX = 1000;
// const int CENTER_X = 200;
// const int CENTER_Y = 200;
using namespace std;

int matrix[MAX][MAX];

vector<pair<int,int> >motion;
void make_motion()
{
    motion.push_back(make_pair(0,1)); //right
    motion.push_back(make_pair(1,0)); //down
    motion.push_back(make_pair(0,-1));//left
    motion.push_back(make_pair(-1,0));//up
}

int main()
{
    make_motion();
    int n = 0;
    cin>>n;
    int times = n * n;
    int nums = 1;
    //找到中心点 你可以试试 一定是 （（n-1） /2 ，（n-1）/2 ）
    int x = (n-1) / 2; int y = (n-1) / 2 ;
    matrix[x][y] = nums;
    int status = 0;
    times --;
    while(times--)
    {
        //如果下面一个元素不为0就一直往右走
        if(status == 0)
        {
            nums++;
            x += motion[status].first; y+= motion[status].second;
            matrix[x][y] = nums;
            if(matrix[x+1][y] == 0)status = 1;
        }
        //如果左边元素不为0就一直向下走 （或者越界了也换状态）
        else if(status == 1)
        {
            nums++;
            x += motion[status].first; y+= motion[status].second;
            matrix[x][y] = nums;
            if(y - 1 < 0 ||matrix[x][y - 1] == 0)status = 2;
        }
        //如果上上面元素不为0一直往左走（越界了也换状态）
        else if(status == 2)
        {
            nums++;
            x += motion[status].first; y+= motion[status].second;
            matrix[x][y] = nums;
            if(x - 1 < 0 || matrix[x - 1][y] == 0)status = 3;
        }
        //如果右边元素不为0一直向上走（越界了也换状态）
        else if(status == 3)
        {
            nums++;
            x += motion[status].first; y+= motion[status].second;
            matrix[x][y] = nums;
            if(matrix[x][y + 1] == 0)status = 0;
        }
    }
    for(int i = 0 ; i < n ; i ++)
    {
        for(int j = 0 ; j < n ; j ++)
        {
            if(matrix[i][j])
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }

}
