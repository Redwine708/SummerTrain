#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct Student{
    string _name;
    string _number;
    int _grade;
    Student(string name, string number,int grade)
    {
        _name = name;
        _number = number;
        _grade = grade;
    }
};
vector<Student>student;
bool compare(Student a , Student b)
{
    return a._grade < b._grade;
}
int main()
{
    int n = 0;
    cin>>n;
    int t = n;
    while(n--)
    {
        string name;string number ; int grade;
        cin>>name>>number>>grade;
        student.push_back(Student(name,number,grade));
    }
    sort(student.begin(),student.end(),compare);
    cout<<student[t-1]._name<<" "<<student[t-1]._number<<endl;
    cout<<student[0]._name<<" "<<student[0]._number<<endl;
    
}