
//#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <list>
#define MAX 100001
using namespace std;

int N,M;
vector<int> A[MAX];
bool visited[MAX];
int X[MAX];

void input(){
	cin>>N>>M;
	for(int i = 1; i <= M; i++){
		int u,v;
		cin>>u>>v;
		A[u].push_back(v);
		A[v].push_back(u);
	}
}

void init(){
	for(int v = 1; v <=N; v++) visited[v] = false;
}
void solution(){
	for(int i = 1; i <=N; i++){
		cout<<X[i]<<" ";
	}
	cout<<endl;
}
bool checkAdj(int u, int v){
	for(int i = 0; i < A[u].size(); i++){
		if (A[u][i] == v) return true;
	}
	return false;
}

void TRY(int k){
	for(int i = 0; i< A[X[k-1]].size(); i++){
		int v = A[X[k-1]][i];
		if(!visited[v]){
			X[k] = v;
			visited[v] = true;
			if(k == N){
				if(checkAdj(X[N], X[1])){
					solution();
				}
			}
			else{
			TRY(k+1);
			}
			visited[v] = false;
		}

	}

}
void TRY(){
	init();
	X[1] = 1;
	visited[1] = true;
	TRY(2);
}
int main(){
	input();
	TRY();
}

/*
7 12
1 2
1 3
2 3
2 4
2 7
3 7
4 5
4 6
4 7
5 6
5 7
3 5
*/
