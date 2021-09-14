#include<iostream>
#include<vector>
#include<string> 
using namespace std;

void command(vector<int>& memory, vector<int>& registers, char commandChar)
{
	switch(commandChar)
	{
		case 'A' : 
			registers[0] = memory[0];break;
		case 'B':
			registers[1] = memory[1];break;
		case 'C':
			memory[0] = registers[2];break;
		case 'D':
			memory[1] = registers[2];break;
		case 'E':
			registers[2] = registers[0] + registers[1]; break;
		case 'F':
			registers[2] = registers[0] - registers[1]; break;
		default:
			cout<<"Please input correct char !"<<endl;
			
	}
}
int main()
{
	int a,b;
	while(cin>>a>>b){
	vector<int>memory(2,0); 
	vector<int>registers(3,0);
	
	memory[0] = a; memory[1] = b;
	string commands;
	cin>>commands;
	for(int i = 0; i < commands.size() ; i ++)
	{
		command(memory, registers, commands[i]);
	}
	cout<<memory[0]<<","<<memory[1]<<endl;
}
 	return 0;	
} 




