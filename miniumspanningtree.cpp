#include <iostream>
#include <vector> 
#define MAX 100010
using namespace std;

int N, M;
vector<int> A[MAX];

int d[MAX];
int f[MAX];
int p[MAX];
vector<int> w[MAX];
char color[MAX];
int t;
int minWs;
int weightsum;

void printTable(){
	for(int v= 1; v <= N; v++){
		cout<<"d["<<v<<"] = "<<d[v]<< "  f["<<v<<"] = "<<f[v]<<"  p["<<v<<"] = "<<p[v]<<"  color["<<v<<"] = "<<color[v];
		cout<<endl;
	}
	cout<<endl;
}

void DFS(int u){
	printTable();	
	t = t + 1;
	d[u] = t;
	color[u] = 'G';
	for(int i = 0; i < A[u].size(); i++){
		int v = A[u][i];
		if(color[v] == 'W'){
			weightsum += w[u][i];
			p[v] = u;
			DFS(v);
		}
	}
	t = t + 1;
	f[u] = t;
	color[u] = 'B';
}
void DFS(){
	for(int v = 1; v <= N; v++){
		color[v] = 'W';
	}
	t = 0;
	minWs = 100000;
	for(int v =1; v <= N; v++)
		if(color[v] == 'W'){
			weightsum = 0;			
			DFS(v);
			if(minWs > weightsum) minWs = weightsum;
			printf("tplt ws = %d", weightsum);
			weightsum = 0;
		}
	printTable();	
}
int input(){
	cin>>N>>M;
	int u,v,weight;
	for(int i = 1; i <= M; i++){	
		cin>>u>>v>>weight;
		A[u].push_back(v);
		A[v].push_back(u);
		w[u].push_back(weight);
		w[v].push_back(weight);
	}
}
void printGraph(){
	for(int v = 1; v <= N; v++){
		cout<<"A["<<v<<"] = ";
		for(int i = 0; i <A[v].size(); i++){
			cout<<A[v][i]<<" ";
		}
		cout<<endl;
	}
}

main(){
	input();
	printGraph();
	DFS();
//	printTable();
	cout<<minWs;
}
