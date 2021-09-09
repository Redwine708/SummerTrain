#include<iostream>
#include<vector>
#include<algorithm> 
#include<string>
const int MAXSIZE = 12;
using namespace std;

// int main()
// {
//     cout<<2<<endl
//         <<"dasha 2 23 789"<<endl
//         <<"ivan 4 2 123 456 789";
// }

bool judgeSub(string _first, string _second)
{
    int fSize = _first.size();
    int sSize = _second.size();
    if(fSize < sSize){return false;}
    if(_first.substr(fSize - sSize) == _second)return true;
    else return false;
}

struct PersonPNum
{
    string _name;
    vector<string>_phoneNum;
    PersonPNum(string name)
    {
        _name = name;
        _phoneNum.resize(MAXSIZE);
    }
};

vector<PersonPNum> person;

bool compare(PersonPNum first, PersonPNum second)
{
    return first._name < second._name;
}
int main()
{
    int n = 0;
    cin>>n;
    getchar();
    string text;
    while(n--)
    {
        getline(cin,text);
        string name;
        string phoneNum;
        int sizeOff = 0;
        //store name
        for(int i = 0 ; i < text.size() ; i ++)
        {
            if(text[i] != ' ')
            {
                name+=text[i];
            }
            else 
            {
                sizeOff = i; break;
            }
        }
        bool nameFlag = 1;
        for(int i = 0 ; i < person.size() ; i ++)
        {
            if(person[i]._name == name)
            {
                nameFlag = 0;  
                break;
            }
        }
        if(nameFlag || person.empty() )
        {
            person.push_back(PersonPNum(name));

        }
        vector<PersonPNum>::iterator iter = person.begin();
        for(; iter != person.end() ; iter++)
        {
            if((*iter)._name == name)
            {
                break;
            }
        }
        for(int i = sizeOff + 1 ; i < text.size() ; i ++)
        {
            if( text[i] != ' ')
            {
                phoneNum += text[i];
            }
            else
            {
                if((*iter)._phoneNum.empty() )(*iter)._phoneNum.push_back(phoneNum);
                else{ 
                    for( vector<string>::iterator iter2 = (*iter)._phoneNum.begin();
                        iter2 != (*iter)._phoneNum.end() ; iter2 ++ )
                        {
                            string _first = *iter2 ;
                            // if( ! judgeSub(_first, phoneNum) )
                            // {
                            //     (*iter)._phoneNum.push_back(phoneNum);
                            // }
                            (*iter)._phoneNum.push_back(phoneNum);
                        }
                }
                phoneNum = "";
            }
        }
        
    }
    sort( person.begin(),person.end(),compare);
    for(int i = 0 ; i < person.size() ; i ++)
    {
        sort(person[i]._phoneNum.begin(),person[i]._phoneNum.end());
    }
    //
    cout<<person.size()<<endl;
    for(int i = 0 ; i < person.size() ; i ++)
    {
        cout<<person[i]._name;
        for(vector<string>::iterator iter2 = person[i]._phoneNum.begin();
                    iter2 != person[i]._phoneNum.end() ; iter2++ )
                    {
                        cout<<*iter2;
                    }
        cout<<endl;
    }
}