//#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <list>
#define MAX 100001
using namespace std;

int N,M,K;
vector<int> A[MAX];
int visited[MAX];
int X[MAX];
int count;
int index;
void input(){
	cin>>N>>M>>K;
	for(int i = 1; i <= M; i++){
		int u,v;
		cin>>u>>v;
		A[u].push_back(v);
		A[v].push_back(u);
	}
}

void init(){
	index = 0;
	for(int v = 1; v <=N; v++) visited[v] = 0;
}

int checkAdj(int u, int v){
	for(int i = 0; i < A[u].size(); i++){
		if (A[u][i] == v) return 1;
	}
	return 0;
}

void TRY(int k){
	for(int i = 0; i< A[X[k-1]].size(); i++){
		int v = A[X[k-1]][i];
		if(!visited[v]){
//			cout<<X[k-1]<<" den "<<v<<endl;
			X[k] = v;
			visited[v] = 1;
			if(k == K){
				if(checkAdj(X[K], X[1])){
//					cout<<"ok"<<endl;
					count++;
				}
				else{
//					cout<<"loai"<<endl;
				}
			}
			else{
			TRY(k+1);
			}
			visited[v] = 0;	
		}
	}
}
void TRY(){
	init();
	count = 0;
	for(int i = 1; i <= N; i++){
//		cout<<"vong dinh "<<i<<": "<<endl;
		X[1] = i;
		visited[i] = 1;
		TRY(2);	
//		cout<<"count = "<<count<<endl;
	}
	cout<<count/2;
}
int main(){
	input();
	TRY();
}

/*
5 7 4
1 2
1 3
2 3
2 4
2 5
3 4
4 5
*/
