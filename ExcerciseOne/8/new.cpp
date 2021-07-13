#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
//#define MAXSIZE 100001
using namespace std;

// char equalt[MAXSIZE][18];
// int index = 0;
struct people

{

    char id[19]; /* 身份证号码 */

    int social; /* 社保缴纳月数 */

    int area; /* 现有住房面积 */

    char date[11]; /* 申报日期 */
};

// bool compare(people _first, people _second)
// {
//     if(_first.social != _second.social)
//         return _first.social > _second.social;
//     if(_first.area != _second.area)
//         return _first.area < _second.area;
//     for(int i = 0 ; i < 10 ; i ++)
//     {
//         if(_first.date[i] != _second.date[i])
//         {
//             return _first.date[i] < _second.date[i];
//         }
//     }

//     return true;
// }

bool compare(people a, people b)
{
    bool firstSituation = (a.area == 0 && a.social > 24 /*two years*/);
    bool secondSituation = (b.area == 0 && b.social > 24 /*two years*/);
    //both are rigid demand
    if (firstSituation &&
        secondSituation)
    {
        if (a.social != b.social)
            return a.social > b.social;
        else
        {
            for (int i = 0; i < 10; i++)
            {
                if (a.date[i] != b.date[i])
                {
                    return a.date[i] < b.date[i];
                }
            }
        }
    }
    //one of the two is rigid demand
    else if (firstSituation ||
             secondSituation)
    {
        if (firstSituation)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    else
    {
        if (a.area != b.area)
            return a.area < b.area;
        else
        {
            for (int i = 0; i < 10; i++)
            {
                if (a.date[i] != b.date[i])
                {
                    return a.date[i] < b.date[i];
                }
            }
        }
    }
}
bool isIdEqual(char *source, char *dest)
{
    for (int i = 0; i < 18; i++)
    {
        if (source[i] != dest[i])
            return false;
    }
    return true;
}
people *getMess(int &n);

bool calculateIsSameRank(people *person, int pos)
{
    people a = person[pos - 1];
    people b = person[pos];
    {
        bool firstSituation = (a.area == 0 && a.social > 24 /*two years*/);
        bool secondSituation = (b.area == 0 && b.social > 24 /*two years*/);
        //both are rigid demand
        if (firstSituation &&
            secondSituation)
        {
            if (a.social != b.social)
                return false;
            else
            {
                for (int i = 0; i < 10; i++)
                {
                    if (a.date[i] != b.date[i])
                    {
                        return false;
                    }
                    return true;
                }
            }
        }
        //one of the two is rigid demand
        else if (firstSituation ||
                 secondSituation)
        {
            if (firstSituation)
            {
                return false;
            }
            else
            {
                return false;
            }
        }
        else
        {
            if (a.area != b.area)
                return false;
            //else if(a.)
            else
            {
                for (int i = 0; i < 10; i++)
                {
                    if (a.date[i] != b.date[i])
                    {
                        return false;
                    }
                }
                return true;
            }
        }
    }
}
void calculateRank(people *person, int n, vector<pair<pair<people, int>, int>> &rank)
{
    int rankNums = 1;

    for (int i = 0; i < n; i++)
    {
        int personNums = 1;
        bool flag = false;
        if (i != 0)
        {
            flag = calculateIsSameRank(person, i);
        }
        bool capable = true;
        if (person[i].social < 24 /*Two years*/ && person[i].area == 0)
            capable = false;
        if (capable == false)
        {
            rank.push_back(make_pair(make_pair(person[i], rankNums), 0));
        }
        else
        {
            //do not have the same position
            if (flag == false)
            {
                if (i != 0)
                    rankNums++;
                rank.push_back(make_pair(make_pair(person[i], rankNums), personNums));
            }
            //have the same position
            else
            {
                vector<pair<pair<people, int>, int>>::iterator iter = rank.end();
                iter--;
                personNums += (*iter).second;
                rank.push_back(make_pair(make_pair(person[i], rankNums), personNums));
                iter = rank.begin();
                for (; iter != rank.end(); iter++)
                {
                    if ((*iter).first.second == rankNums)
                        (*iter).second = personNums;
                }
            }
        }

        // for(int i = 0 ; i < 18 ; i ++)
        // {
        //     equalt[index][i] = person[i].id[i];
        // }
        // index++;
    }
}
int main()

{

    people *person; /* 指向所有报名人的基本资料首地址，通过调用函数getMess获取 */

    int n; /* n为报名人数，通过调用函数getMess获取 */

    person = getMess(n);
    for (int i = 0; i < n; i++)
    {
        cout << person[i].id << " " << person[i].social << " " << person[i].area << person[i].date << endl;
    }
    cout << endl;
    for (int i = 0; i < n; i++)
    {
        char tmp[10];
        int off = 0;
        for (int j = 6; j < 10; j++)
        {
            tmp[off++] = person[i].date[j];
        }
        for (int j = 0; j < 2; j++)
        {
            tmp[off++] = person[i].date[j];
        }
        for (int j = 3; j < 5; j++)
        {
            tmp[off++] = person[i].date[j];
        }
        for (int j = 0; j < 10; j++)
        {
            person[i].date[j] = tmp[j];
        }
    }
    sort(person, person + n, compare);
    for (int i = 0; i < n; i++)
    {
        cout << person[i].id << " " << person[i].social << " " << person[i].area << " " << person[i].date << endl;
    }
    vector<pair<pair<people, int>, int>> rank;
    calculateRank(person, n, rank);
    for (int i = 0; i < n; i++)
    {
        cout << rank[i].first.second << " " << rank[i].second << endl;
    }
    int m = 0;
    int T = 0;
    std::cin >> m >> T;
    //store id
    string id;
    int repetition = 0;
    int flag1 = true;
    int count2 = 0;
    int flag2 = true;
    int originRankNums = 0;
    int originRankNums2 = 0;
    int flag3 = true;
    int count3 = 0;
    unordered_map<string, string> table;
    for (int i = 0; i < rank.size(); i++)
    {
        if (originRankNums != rank[i].first.second && originRankNums != 0)
        {
            m -= count2;
            count2 = 0;
            flag2 = true;
        }
        if (count3 != 0 && originRankNums2 != rank[i].first.second && originRankNums2 != 0 && !(rank[i].second == 0 || m <= 0))
        {
            int t = 0;
            for (int j = 0; j < n; j++)
            {
                if (rank[j].first.second == originRankNums2)
                {
                    t = j;
                    break;
                }
            }
            repetition += (count3 - 1);
            count3 = 0;
        }
        if (rank[i].second == 0 || m <= 0)
        {
            string tmp;
            for (int j = 0; j < 18; j++)
            {
                tmp += rank[i].first.first.id[j];
            }
            table[tmp] = "Sorry";
            flag1 = false;
            cout << table[tmp] << endl;
        }
        else if (rank[i].second == 1)
        {
            string tmp;
            for (int j = 0; j < 18; j++)
            {
                tmp += rank[i].first.first.id[j];
            }

            int value = rank[i].first.second + repetition;
            table[tmp] = to_string(value);
            cout << table[tmp] << endl;
        }
        else if (rank[i].second <= m)
        {

            string tmp;
            for (int j = 0; j < 18; j++)
            {
                tmp += rank[i].first.first.id[j];
            }
            if (count3 == 0)
            {
                originRankNums2 = rank[i].first.second;
                count3++;
            }
            else
            {
                if (originRankNums2 != rank[i].first.second)
                {
                    originRankNums2 = rank[i].first.second;
                    count3 = 1;
                }
                else
                    count3++;
            }
            table[tmp] = to_string(rank[i].first.second) + " " + to_string(rank[i].first.second + rank[i].second - 1);
            cout << table[tmp] << endl;
            //repetition += rank[i].second;
        }
        else
        {
            string tmp;
            for (int j = 0; j < 18; j++)
            {
                tmp += rank[i].first.first.id[j];
            }
            //first time to record
            if (count2 == 0)
            {
                originRankNums = rank[i].first.second;
                count2++;
            }
            else
            {
                if (originRankNums != rank[i].first.second)
                {
                    count2 = 0;
                    // originRankNums = rank[i].first.second;
                }
                else
                    count2++;
            }
            flag2 = false;
            table[tmp] = to_string(m) + "/" + to_string(rank[i].second);
            cout << table[tmp] << endl;
        }
        if (flag1 && flag2)
        {
            m -= 1;
            //repetition += rank[i].second;
        }
        flag1 = true;
    }

    while (T--)
    {

        //cout<<id;
        //find and cout
        cin >> id;
        cout << table[id] << endl;
    }
}
people *getMess(int &n) /* 将文件数据读入内存 */

{

    FILE *fp;

    fp = fopen("house.bin", "rb");

    fseek(fp, -1 * (long)sizeof(int), 2);

    fread(&n, sizeof(int), 1, fp);

    rewind(fp);

    people *tmp = new people[n];

    fread(tmp, sizeof(people), n, fp);

    fclose(fp);

    return tmp;
}
