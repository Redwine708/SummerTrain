#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std;

char equalt[13][18];
int index = 0;
struct people

{

    char id[19];                  /* 身份证号码 */

    int social;                     /* 社保缴纳月数 */

    int area;                       /* 现有住房面积 */

    char date[11];              /* 申报日期 */

};

bool compare(people _first, people _second)
{
    if(_first.social != _second.social)
        return _first.social > _second.social;
    if(_first.area != _second.area)
        return _first.area < _second.area;
    for(int i = 0 ; i < 10 ; i ++)
    {
        if(_first.date[i] != _second.date[i])
        {
            return _first.date[i] < _second.date[i];
        }
    }

    return true;
}

bool isIdEqual(char* source,char* dest)
{
    for(int i = 0 ;  i < 18 ; i ++ )
    {
        if(source[i] != dest[i])return false;
    }
    return true;
}
people* getMess(int &n);

void calculateRank(people* person, int n, vector< pair< pair<people,int> , int> >&rank)
{
    int rankNums = 1;
    
    for(int i = 0 ; i < n ; i ++)
    {
        int personNums = 1;
        bool flag = true;
        for(int i = 0 ; i < 13 ; i++)
        {
            if(isIdEqual(person[i].id, equalt[i]))
            {
                flag = false;
                break;
            }
        }
        bool capable = true;
        if(person[i].social < 2) capable = false;
        if(capable == false)
        {
            rank.push_back( make_pair(make_pair(person[i],rankNums),0) );
        }
        else
        {
            //do not have the same position
            if(flag == true)
            {
                rankNums++;
                rank.push_back( make_pair(make_pair(person[i],rankNums),personNums) );

            }
            //have the same position
            else
            {
                vector< pair< pair<people,int> , int> >::iterator iter = rank.end();
                iter--;
                personNums += (*iter).second; 
                rank.push_back( make_pair(make_pair(person[i],rankNums),personNums) );
            }
        }
        if(i == 0)
        {
            
            for(int i = 0 ; i < 18 ; i ++)
            {
                equalt[index][i] = person[i].id[i];
            }
            index++;
        }
    }
}
int main()

{

    people *person;          /* 指向所有报名人的基本资料首地址，通过调用函数getMess获取 */     

    int n;                            /* n为报名人数，通过调用函数getMess获取 */

    person=getMess(n);
    // for(int i = 0 ;  i < n ; i ++)
    // {
    //     cout<<person[i].social<<" "<<person[i].area<<endl;
    // }
    
    for(int i = 0 ; i < n ;  i++)
    {
        char tmp[10];
        int off = 0;
        for(int j = 6 ; j < 10 ; j ++)
        {
            tmp[off++] = person[i].date[j];
        }
        for(int j = 0 ; j < 2 ; j ++)
        {
            tmp[off++] = person[i].date[j];
        }
        for(int j = 3 ; j < 5 ; j ++)
        {
            tmp[off++] = person[i].date[j];
        }
        for(int j = 0 ; j < 10 ; j ++)
        {
            person[i].date[j] = tmp[j];
        }
    }
    sort(person, person + n , compare);
    for(int i = 0 ;  i < n ; i ++)
    {
        cout<<person[i].social<<" "<<person[i].area<<person[i].date[0]<<endl;
    }
    vector< pair< pair<people,int> , int> >rank;
    calculateRank(person,n,rank);
    int m = 0; int T = 0;
    std::cin>>m>>T;
    //store id 
    char id[18];
    while(T --)
    {
        scanf("%s",&id);
        //cout<<id;
        for(int i = 0 ; i < rank.size() ; i ++)
        {
            if(isIdEqual(rank[i].first.first.id, id) )
            {
                if(rank[i].second == 0)
                {
                    cout<<"Sorry"<<endl;
                    continue;
                }
                else if(rank[i].first.second == 1)
                {
                    cout<<rank[i].first.second<<endl;
                    continue;
                }
                else if(rank[i].second <= m)
                {
                    cout<<rank[i].first.second<<" "<<rank[i].first.second + rank[i].second<<endl;
                }
                else {
                    cout<<m<<"/"<<rank[i].second<<endl;
                }
            }
            m -= rank[i].second;
        }
    }
    // ..
    return 0;

}

people* getMess(int &n)            /* 将文件数据读入内存 */

{

    FILE *fp;

    fp=fopen("house.bin","rb");

    fseek(fp,-1 * (long)sizeof(int), 2);

    fread(&n, sizeof(int),1, fp);

    rewind(fp);

    people *tmp=new people[n];

    fread(tmp, sizeof(people), n, fp);

    fclose(fp);

    return tmp;

}
