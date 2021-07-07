#include<iostream>
#include<stack>
#include<string>
//store data


bool validPara(std::string parantheses)
{
    std::stack<char>table;
    int size = parantheses.size();
    //special judge
    if(parantheses[0] == ']' || parantheses[0] == '}' || parantheses[0] == '>'
        || parantheses[0] == ')')return false;
    for(int i = 0; i < size ; i ++)
    {
        if(parantheses[i] == '[' || parantheses[i] == '{' ||
            parantheses[i] == '<' || parantheses[i] == '(')
            {
                table.push(parantheses[i]);
            }
        else
        {
            char tableTop ;
            if(table.empty() ) return false;
            else
                tableTop = table.top();
            if(
                 ( tableTop == '(' && parantheses[i]  == ')' ) ||
                 ( tableTop == '{' && parantheses[i]   == '}' ) ||
                ( tableTop == '<' && parantheses[i] == '>' ) ||
                ( tableTop == '[' && parantheses[i] == ']' ) 
                                                                        )
                    {
                        table.pop();
                    }
            else
            {
                return false;
            }
        }
    }
    //If the stack is still not empty
    if( table.empty() )return true;
    else 
    {return false;}
}
int main()
{
    int testNums = 0;
    std::string parantheses;
    std::cin>>testNums;
    while(testNums--)
    {
        std::cin>>parantheses ;
        if(validPara(parantheses))
        {
            std::cout<<"Yes"<<std::endl;
        }
        else{
            std::cout<<"No"<<std::endl;
        }
    }
}

