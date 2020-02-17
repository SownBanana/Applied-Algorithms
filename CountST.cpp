//#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <list>
#define MAX 100001
using namespace std;

int N,M;
vector<int> A[MAX];
//int b[MAX];				//begining
//int e[MAX];				//ending

//int rank[MAX];         //rank
int r[MAX]; 		//p[v] is parent(root) of v

int X[MAX];
int count;
bool visited[MAX];
bool blacklist[MAX];

void input(){
	cin>>N>>M;
	for(int i = 1; i <= M; i++){
		int u,v;
		cin>>u>>v;
		A[u].push_back(v);
		A[v].push_back(u);
//		b[i] = u;
//		e[i] = v;
	}
}
void makeRoot(int x){
	r[x] = x;
//	rank[x] = 0;
}
void init(){
	for(int i = 1; i <= N; i++){
		visited[i] = false;
		makeRoot(i);
	}
}

int root(int x) {
	if (r[x] = x) return x;
	else {
//		r[x] = root(r[x]);  			//compress root[root[x]] = Root(root[x])	root[x] = root[root[x]]
//		return r[x];
		return root(r[x]);  
	}
}

void merge(int x, int y) {
	int rx= root(x);
	int ry = root(y);
	if (rx != ry) r[rx] = ry;
}
bool checkAdj(int v, int bef){
	for(int i = 0; i < A[bef].size(); i++){
		if(v == A[bef][i]) return true;
	}
	return false;
}

bool check(int u, int v){
	int ru = root(u);
	int rv = root(v);
	if (ru != rv) {
		merge(ru, rv);
		return true;
	}
	return false;
}


void TRY(int k){
	for(int v = 1; v <= N; v++){
		if(!visited[v] && checkAdj(v, X[k-1]) && (X[k-1], v)){
//			cout<<k<<endl;
			visited[v] = true;
			X[k] = v;
//			for (int i = 1; i <= N; i++){
//					cout<<X[i]<<" ";
//			}
//			cout<<endl;
			if(k == N){
				if(1){
					count += 1;
					for (int i = 0; i <= N; i++){
						cout<<X[i]<<" ";
					}
					cout<<endl;
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
	for(int i= 1; i <= N; i++) blacklist[i] = false;
	count = 0;
	for(int i = 1; i <= N; i++){
		init();
		visited[i] = true;
		X[1] = i;
		TRY(2);
		blacklist[i] = true;
	}
	
}
int main(){
	input();
	TRY();
	cout<<count;
}

/*
4 5
1 2
1 3
1 4
2 3
3 4
*/
