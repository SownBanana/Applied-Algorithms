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
int nodeCounter;
int maxNodes;

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
		if (v == A[u][i]) return true;
	}
	return false;
}
bool checkClique(int k, int v){
	for(int i = 1; i < k; i++){
		if (!checkAdj(X[i], v)){
			return false;
		} 
	}
	return true;
}
void TRY(int k){
	for(int i = 0; i< A[X[k-1]].size(); i++){
		int v = A[X[k-1]][i];
		if(!visited[v] && checkClique(k, v)){
			X[k] = v;
			nodeCounter += 1;
			visited[v] = true;
			if(maxNodes < nodeCounter) maxNodes = nodeCounter;
			else{
			TRY(k+1);
			}
			nodeCounter -= 1;
			visited[v] = false;	
		}	
	}
}
void TRY(){
	init();
	maxNodes = 0;
	for (int i = 1; i <= N; i++){
//		cout<<"vong "<<i<<": "<<endl;
		X[1] = i;
		nodeCounter = 1;
		visited[i] = true;
		TRY(2);
	}
	cout<<maxNodes<<endl;
}
int main(){
	input();
	TRY();
}

/*
5 8
1 2
1 3
2 3
2 4
2 5
3 4
3 5
4 5
*/
