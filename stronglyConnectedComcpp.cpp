#include <iostream>
#include <vector> 
using namespace std;

#define MAX 100001

int N, M;
vector<int> A[MAX];
vector<int> At[MAX]; //complement graph
int f[MAX];			//finish visit

int resortf[MAX];

char color[MAX];
int t;
int count;


int input(){
	cin>>N>>M;
	int u,v;
	for(int i = 1; i <= M; i++){	
		cin>>u>>v;
		A[u].push_back(v);
		At[v].push_back(u);
	}
}

void DFS(int u){
	t = t + 1;
	color[u] = 'G';
	for(int i = 0; i < A[u].size(); i++){
		int v = A[u][i];
		if(color[v] == 'W'){
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
	for(int v =1; v <= N; v++)
		if(color[v] == 'W'){
			DFS(v);
		}
}

void resortF(){
	int index = 1;
	while(index <= N){
		int max = 0;
		int rsi = 0;
		for(int i = 1; i <= N; i++){
			if(f[i] > max){
				max = f[i];
				rsi = i;
			}
		}
		resortf[index++] = rsi;
		f[rsi] = 0;
	}
}
void DFST(int u){
	color[u] = 'G';
	for(int i = 0; i < At[u].size(); i++){
		int v = At[u][i];
		if(color[v] == 'W'){
			DFST(v);
		}
	}
	color[u] = 'B';
}
void DFST(){
	resortF();
	for(int v = 1; v <= N; v++){
		color[v] = 'W';
	}
	count = 0;
	for(int i = 1; i <= N; i++){
		int v = resortf[i];
		if(color[v] == 'W'){
			count += 1;
			DFST(v);
		}
	}
		
}

main(){
	input();
	DFS();	
	DFST();
	cout<<count;
}
