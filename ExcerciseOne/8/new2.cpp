#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
using namespace std;

struct People{//题给的结构体，注意该结构体不能修改，避免文件读取错误
    char id[19];                  /* 身份证号码 */
    int social;                     /* 社保缴纳月数 */
    int area;                       /* 现有住房面积 */
    char date[11];              /* 申报日期 */
};

struct people{//魔改的结构体
    string id;                  /* 身份证号码 */
    int social;                     /* 社保缴纳月数 */
    int area;                       /* 现有住房面积 */
    string date;              /* 申报日期 */
    int dateint=0;//日期拼接成的整数
    int rank=0;//排名
    int samerank=0;//并列排名的人数
};

vector<string> split(string s,string separate){//字符串分段函数
    vector<string> splited;
    unsigned int separate_len=separate.length();
    unsigned int start=0;
    int index;
    while((index=s.find(separate,start))!=-1){
        splited.push_back(s.substr(start,index-start));
        start=index+separate_len;
    }
    if(start<s.length()){
        splited.push_back(s.substr(start,s.length()-start));
    }
    return splited;
}

bool compare1(people data1,people data2){//刚性需求自定义排序
    if (data1.social==data2.social){
        return data1.dateint < data2.dateint;
    }
    else{
        return data1.social>data2.social;
    }
}

bool compare2(people data1,people data2){//改善性需求自定义排序
    if (data1.area==data2.area){
        return data1.dateint < data2.dateint;
    }
    else{
        return data1.area<data2.area;
    }
}

People* getMess(int &n){//题给的读文件函数
    FILE* fp;
    fp=fopen("house.bin","rb");
    fseek(fp,-1*(long)sizeof(int), 2);
    fread(&n, sizeof(int),1, fp);
    rewind(fp);
    People* tmp=new People[n];
    fread(tmp, sizeof(People), n, fp);
    fclose(fp);
    return tmp;
}

int main(){
    People *Person;          /* 指向所有报名人的基本资料首地址，通过调用函数getMess获取 */    
    int n;                            /* n为报名人数，通过调用函数getMess获取 */
    Person=getMess(n);//开始读文件
    people *person=new people[n];  //构造自己魔改的结构体
    for(int i=0;i<n;i++){//复制原结构体的数据
        person[i].area=Person[i].area;
        person[i].date=Person[i].date;
        person[i].id=Person[i].id;
        person[i].social=Person[i].social;
    }
    stringstream ss;//字符串流，用于将字符串转成整数
    for(int i=0;i<n;i++){
        vector<string> temp2;
        temp2=split(person[i].date,"-");
        string temp3;
        temp3=temp2[2]+temp2[1]+temp2[0];   //按年+月+日的形式拼接起来     
        ss.clear();
        int dateint;
        ss<<temp3;
        ss>>dateint;
        person[i].dateint=dateint;
    }
    
    vector<people> first;//第一批，满足刚性需求的人
    vector<people> second;//第二批，满足改善性需求的人
    vector<people> sorry;//第三批，SorryMaker，不满足购房条件的人
    for(int i=0;i<n;i++){//将报名人群分批
        if(person[i].area!=0){//已有住房面积大于零，则为改善性需求人群
            second.push_back(person[i]);
        }else if(person[i].social>24){//住房面积为零且社保缴纳超过2年（即24个月），则为刚性需求人群
            first.push_back(person[i]);
        }else{//其他则为SorryMaker人群
            sorry.push_back(person[i]);
        }
    }
    sort(first.begin(),first.end(),compare1);//对第一批排序
    sort(second.begin(),second.end(),compare2);//对第二批排序
    int rank=1;//排名临时变量
    int count=1;//并列排名人数临时变量
    int index=0;//赋值下标
    for(unsigned int i=0;i<first.size();i++){//对第一批进行排名及并列人数标记
        if(i==first.size()-1){//如果到了最后一个人
            if(count!=1){//若并列人数大于1，要进行赋值
                for(int j=index;j<index+count;j++){//对并列人群赋值
                    first[j].rank=rank;
                    first[j].samerank=count;
                }
                index+=count;
                rank+=count;//下一个（一群）人的排名
                count=1;//赋值完后count要初始化
                break;
            }else if(first[i].rank!=0){//如果他已经有排名则退出
                break;
            }else{//还没有排名则赋值
                first[i].rank=rank;
                first[i].samerank=1;
                rank+=1;
                break;
            }
        }
        if((first[i].social==first[i+1].social)&&(first[i].dateint==first[i+1].dateint)){//如果条件相同
            count++;//则并列人数加1
        }else{ 
            if(count!=1){//条件不同且当前并列人数多于1，则需要对这些人的排名和并列人数进行赋值
                for(int j=index;j<index+count;j++){//对并列人群赋值
                    first[j].rank=rank;
                    first[j].samerank=count;
                }
                index+=count;
                rank+=count;//下一个（一群）人的排名
                count=1;//赋值完后count要初始化
            }else{//count=1，则只有一人
                first[i].rank=rank;
                first[i].samerank=1;
                rank+=1;
                index+=1;
            }
        }
    }
    index=0;//下标初始化
    for(unsigned int i=0;i<second.size();i++){//对第二批进行排名及并列人数标记
        if(i==second.size()-1){//如果到了最后一个人
            if(count!=1){//若并列人数大于1，要进行赋值
                for(int j=index;j<index+count;j++){//对并列人群赋值
                    second[j].rank=rank;
                    second[j].samerank=count;
                }
                index+=count;
                rank+=count;//下一个（一群）人的排名
                count=1;//赋值完后count要初始化
                break;
            }else if(second[i].rank!=0){//如果他已经有排名则退出
                break;
            }else{//还没有排名则赋值
                second[i].rank=rank;
                second[i].samerank=1;
                rank+=1;
                break;
            }
        }
        if((second[i].area==second[i+1].area)&&(second[i].dateint==second[i+1].dateint)){//如果条件相同
            count++;//则并列人数加1
        }else{ 
            if(count!=1){//条件不同且当前并列人数多于1，则需要对这些人的排名和并列人数进行赋值
                for(int j=index;j<index+count;j++){//对并列人群赋值
                    second[j].rank=rank;
                    second[j].samerank=count;
                }
                index+=count;
                rank+=count;//下一个（一群）人的排名
                count=1;//赋值完后count要初始化
            }else{//count=1，则只有一人
                second[i].rank=rank;
                second[i].samerank=1;
                rank+=1;
                index+=1;
            }
        }
    }
    int m,t;
    cin>>m>>t;
    for(int i=0;i<t;i++){//读t组数据
        string sfz;
        int flag=1;//标记输出状态，未输出结果则为1，已经输出了则为0
        cin>>sfz;
        for(unsigned int j=0;j<sorry.size();j++){
            if(sfz==sorry[j].id){//如果该人在SorryMakers中，则直接Sorry
                cout<<"Sorry"<<endl;
                flag=0;//标记
                break;
            }
        }
        for(unsigned int k=0;k<first.size();k++){//在第一批人群中查找该人
            if(flag==0){//若之前已经输出，则退出
                break;
            }
            if(sfz==first[k].id){//若找到了该人的数据
                if(first[k].samerank==1){//若排名只有自己一个人
                    if(first[k].rank<=m){//若排名不大于房源数量
                        cout<<first[k].rank<<endl;//输出排名即为选房序号
                        flag=0;
                    }else{//否则Sorry
                        cout<<"Sorry"<<endl;
                        flag=0;
                    }
                }else{//若排名不只自己一人
                    if(first[k].rank>m){//若排名已经大于房源数量则直接Sorry
                        cout<<"Sorry"<<endl;
                        flag=0;
                    }else if(first[k].rank+first[k].samerank-1<=m){//若并列排名的所有人都能买房，则输出区间形式
                        cout<<first[k].rank<<" "<<first[k].rank+first[k].samerank-1<<endl;
                        flag=0;
                    }else{//若所有人已经溢出，则输出分数形式
                        cout<<m-(first[k].rank-1)<<"/"<<first[k].samerank<<endl;
                        flag=0;
                    }
                }
            }
        }
        for(unsigned int q=0;q<second.size();q++){//在第二批人群中查找该人，基本流程同上
            if(flag==0){
                break;
            }
            if(sfz==second[q].id){
                if(second[q].samerank==1){
                    if(second[q].rank<=m){
                        cout<<second[q].rank<<endl;
                        flag=0;
                    }else{
                        cout<<"Sorry"<<endl;
                        flag=0;
                    }
                }else{
                    if(second[q].rank>m){
                        cout<<"Sorry"<<endl;
                        flag=0;
                    }else if(second[q].rank+second[q].samerank-1<=m){
                        cout<<second[q].rank<<" "<<second[q].rank+second[q].samerank-1<<endl;
                        flag=0;
                    }else{
                        cout<<m-(second[q].rank-1)<<"/"<<second[q].samerank<<endl;
                        flag=0;
                    }
                }
            }
        }
        if(flag==1){//如果该身份证号没有被找到，则直接Sorry
            cout<<"Sorry"<<endl;
        }
    }
    return 0;
}