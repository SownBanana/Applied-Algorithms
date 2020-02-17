//#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <list>
#define MAX 100001
using namespace std;

typedef struct a{
	int v;
	int w;
} v_w;

int N;
vector<v_w> A[MAX];		//tree
//vector<vector<int> > W[MAX];
bool visited[MAX];
char color[MAX];
//int X[MAX];
int sum;
int maxW;
int maxV;

//void printGraph(){
//	for(int v = 1; v <= N; v++){
//		cout<<"A["<<v<<"] = ";
//		for(int i = 0; i < A[v].size(); i++){
//			cout<<A[v][i]<<" ";
//		}
//		cout<<endl;
//	}
//}

void input(){
	cin>>N;
	for(int i = 1; i < N; i++){
		v_w u;
		v_w v;
		cin>>u.v>>v.v>>v.w;
		u.w = v.w;
		A[u.v].push_back(v);
		A[v.v].push_back(u);
	}
}


void DFS(int u){
	color[u] = 'G';
	for(int i = 0; i < A[u].size(); i++){
		v_w v = A[u][i];
		if(color[v.v] == 'W'){
			sum += v.w;
//			cout<<v<<endl;
			if(sum > maxW) {
				maxW = sum;
				maxV = v.v;
//				cout<<maxW<<" "<<maxV<<endl;
			}
			DFS(v.v);
			sum -= v.w;
		}
	}
	color[u] = 'B';
}
void DFS(){
	for(int v = 1; v <= N; v++){
		color[v] = 'W';
	}
	sum = 0;
	maxW = 0;
	DFS(1);
	int u = maxV;
//	cout<<u<<" "<<maxW;
	sum = 0;
	maxW = 0;
	for(int v = 1; v <= N; v++){
		color[v] = 'W';
	}
	DFS(u);
//	cout<<maxW;
}
int main(){
	input();
	DFS();
	cout<<maxW;
}

/*
6
1 3 3
1 6 2
2 6 5
4 5 2
4 6 1
*/
