#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>

const int ORIGIN_POS = 1;

using namespace std;
//Three operations alloc erase defragment

//find all leisure space in memory
void findLeisure(vector<pair<int , int> >&findLeisureSpace,vector<int>& memory)
{
    int n = memory.size();
    for(int i = 0 ; i < n ; i ++)
    {
        if(memory[i] == 0 )
        {
            int j = i + 1;
            if(i == (n - 1) )
            {
                findLeisureSpace.push_back( make_pair(i, i ) );
                break;
            }
            else
                for( ; j < n ; j ++)
                {
                    if(memory[j] != 0 )
                    {
                        findLeisureSpace.push_back(make_pair(i, j - 1) );
                        break;
                    }
                    else if(j == n - 1)
                    {
                        findLeisureSpace.push_back(make_pair(i, j) );
                        break;
                    }
                }
            if( j == n - 1)break;
        }
    }
}

int alloc(vector<int>& memory, int& currAllocNums, int space)
{
    currAllocNums++;
    bool isAlreadyAlloc = false;
    vector<pair<int , int> >findLeisureSpace;
    findLeisure(findLeisureSpace, memory);
    bool flag = false;
    for(auto& v : findLeisureSpace)
    {
        int ownSpace = v.second - v.first + 1 ;
        if(ownSpace >= space )
        {
            for(int i = v.first ; i < space + v.first ; i ++)
            {
                memory[i] = currAllocNums;
                flag = true;
            }
        }
    }
    if(flag == true)return currAllocNums;
    else
    {
        currAllocNums--;
        return false;
    }
}

bool erase(vector<int>& memory, int eraseBlock)
{
    int n = memory.size();
    int isErase = false;
    for(int i = 0 ; i < n ; i ++)
    {
        if(memory[i] == eraseBlock)
        {
            memory[i] = 0;
            isErase = true;
        }
    }
    return isErase;
}

void defragment(vector<int>& memory)
{
    int count = 0;
    int n = memory.size();
    // vector<pair<int , int> > findLeisureSpace;
    // findLeisure(findLeisureSpace, memory);
    for(vector<int>::iterator iter = memory.begin() ; iter != memory.end() ; iter++)
    {
        if((*iter) == 0){
            iter = memory.erase(iter);
            count++;
            iter--;
        }
    }
    for(int i = 0 ; i < count ;i ++ )
    {
        memory.push_back(0);
    }
}
int main()
{
    
    int operators = 0 ; 
    int memorySize = 0 ;
    int currAllocNums = 0;
    cin>>operators>>memorySize ;
    vector<int>memory(memorySize,0);
    string operate;
    while(operators --)
    {
        cin>>operate;
        if(operate == "alloc")
        {
            int allocSize = 0;
            cin>>allocSize;
            bool isAlloc = alloc(memory, currAllocNums, allocSize);
            if(!isAlloc )cout<<"NULL"<<endl;
            else cout<<currAllocNums<<endl;
        }
        else if(operate == "erase")
        {
            int eraseBlock = 0;
            cin>>eraseBlock;
            if(! erase(memory,eraseBlock) )
            {
                cout<<"ILLEGAL_ERASE_ARGUMENT"<<endl;
            }
        }
        else{
            defragment(memory);
        }
    }

}
