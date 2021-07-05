/**
 * @file nOrN.cpp
 * @author your name (you@domain.com)
 * @brief time complexity O(m+n)
 * @version 0.1
 * @date 2021-07-05
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include<iostream>
#include<vector>
#include<string>
using namespace std;
//do something
void perform(int m,int n);
//judge whether the number obtains the former number
bool havet(int t , int n);
//KMP algorithm
bool KMP(string text,string pattern);
//get next array
int* getNext(string pattern);
int main()
{
    int m,n;
    cin>>m>>n;
    perform(m,n);
}
/**
 * @brief 
 * 
 */
void perform(int m,int n){
    int t = 0;
    while(++t <= m )
    {
        if(t % n == 0 ||havet(t,n))cout<<t<<" ";
    }

}
bool havet(int t , int n){
    string text;
    //text string
    text = to_string(t);
    string pattern;
    //pattern string
    pattern = to_string(n);
    return KMP(text,pattern);
}
int* getNext(string pattern)
{
    int * next = new int[pattern.size()];
    int n = pattern.size();
    int j = -1;
    next[0] = -1;
    for(int i = 1 ; i < n ; i ++)
    {
        while(j != -1 && pattern[j + 1] != pattern[i])
        {
            j = next[j];
        }
        if(pattern[j + 1] == pattern[i])
        {
            j++ ;
        }
        next[i] = j;
    }
    return next;
}
bool KMP(string text , string pattern){
    //get next
    int n = text.size(), m = pattern.size();
    if(n < m)return false;
    int * next = getNext(pattern);
    int j = -1;
    for(int i = 0 ; i < n ; i ++)
    {
        while( j != -1 && text[i] != pattern[j + 1]){
            j = next[j];
        }
        if(text[i] == pattern[j + 1])j++;
        if(j == m - 1)return true;
    }
    //free space
    delete next;
    return false;
}
//data
//11 22 33 44 55 66 77 88 99 110 111 112 113 114 115 116 117 118 119 121 132 143 154 165 176 187 198
//11 22 33 44 55 66 77 88 99 110 111 112 113 114 115 116 117 118 119 121 132 143 154 165 176 187 198 