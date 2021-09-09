#include<iostream>
#include<algorithm>
#include<vector>
#include<stack>
using namespace std;

const int INF = 1e6;
vector< stack<int> > result;

int minVertex(int* distance, int* mark, int numVertex)
{
	int v = -1,index = 0;
	for(index = 0 ; index < numVertex ; index ++ )
	{
		if( mark[index] == 0 ) {v = index;break;} 
	}
	for( ++index ; index < numVertex ; index ++)
	{
		if(mark[index] == 0 && distance[index] < distance[v] )
			{v = index;break;}
	}
	return v;
}

void dijkstra(int** matrix, int* distance, int* mark, int numVertex, vector<int>* prev )
{
	int v;
	distance[0] = 0;
	for(int i = 0 ; i < numVertex ; i ++)
	{
		v = minVertex(distance, mark, numVertex);
		if(distance[v] == INF )return;
		mark[v] = 1;
		for(int j = 0 ;j < numVertex ; j ++)
		{
			if(distance[j] > distance[v] + matrix[v][j])
			{
				distance[j] = distance[v] + matrix[v][j];
				prev[j].push_back(v);
				//cout<<prev[j][0]<<" ";
			}
		}
	}
}

void BFS(vector<int>* prev, int currDegree, int maxDegree, stack<int>temp, int numVertex)
{
	if(currDegree <= 0 )
	{
		// if(temp.top() == numVertex - 1 )
		result.push_back(temp);
		return ;
	}
	for(int i = 0 ; i < prev[currDegree].size() ; i ++ )
	{
		temp.push( prev[currDegree][i] );
		BFS(prev,currDegree-1 , maxDegree, temp,numVertex);
	}
}

bool compare(stack<int> a, stack<int> b)
{
	while(!a.empty() && !b.empty() )
	{
		if(a.top() != b.top())
			return a.top() < b.top();
		a.pop(); b.pop();
	}
	return true;
}
void calResult(vector<int>* prev , int numVertex)
{
	stack<int>temp;
	BFS(prev, numVertex - 1 , 0 , temp, numVertex);
	sort(result.begin(),result.end(),compare);
	stack<int>result1 = result[0];
	while(!result1.empty())
	{
		cout<<result1.top() + 1 <<" ";
		result1.pop();
	}
	
}


int main()
{
	int vertexNum; int edgeNum;
	cin>>vertexNum>>edgeNum;
	int** matrix = new int* [vertexNum];
	for(int i = 0 ; i < vertexNum ; i ++)
	{
		matrix[i] = new int [vertexNum];
		fill( matrix[i], matrix[i] + vertexNum, INF );
	}
	
	int start,end,weight;
	for(int i = 0 ; i < edgeNum ; i ++ )
	{
		cin>>start>>end>>weight;
		if(matrix[ start - 1 ][ end - 1] != INF 
						&& matrix[start - 1][end - 1] < weight)
				matrix[ start - 1 ][ end - 1] = weight;
		else
			matrix[start - 1][end - 1] = weight;
	}
	
	// for(int i = 0 ; i < vertexNum ; i ++)
	// {
	// 	for(int j = 0 ; j < vertexNum ; j ++)
	// 	{
	// 		cout<<matrix[i][j]<<" ";
	// 	}
	// 	cout<<endl;
	// }
	// cout<<"**************"<<endl;
	int* mark = new int [vertexNum];
	fill(mark, mark + vertexNum , 0 );
	int* distance = new int[vertexNum];
	fill(distance, distance + vertexNum , INF );
	vector<int>* prev = new vector<int> [vertexNum];
	
	dijkstra(matrix,distance,mark, vertexNum,prev );
	calResult(prev, vertexNum);
	cout<<endl<<endl;
	//cout<<prev[0][0]<<" "<<prev[3][0]<<" "<<prev[2][0]<<" "<<prev[4][0]<<endl;
	cout<<endl;
	for(auto v : result)
	{
		while(!v.empty())
		{
			cout<<v.top()<<" ";
			v.pop();
		}
		cout<<endl;
	}
	return 0;
}
