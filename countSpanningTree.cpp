//#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <list>
#define MAX 100001
using namespace std;

int N,M;
int b[MAX];				//begining
int e[MAX];				//ending

int r[MAX];         //rank
int p[MAX]; 		//p[v] is parent(root) of v

int X[MAX];
int count;
//int visited[MAX];

void input(){
	cin>>N>>M;
	for(int i = 1; i <= M; i++){
		cin>>b[i]>>e[i];
	}
}
void makeSet(int x){
	p[x] = x;
	r[x] = 0;
}
void init(){
	for(int i = 1; i <= N; i++){
//		visited[i] = false;
	}
}

int findSet(int x) {
	if (x != p[x])
		p[x] = findSet(p[x]);
	return p[x];
}

void link(int x, int y) {
	if (r[x] > r[y]) p[y] = x;
	else{
		p[x] = y;
		if(r[x] == r[y]) r[y] = r[y] + 1;
	}
}

int check(int val, int k){
	for(int i = 1; i <= N; i++) makeSet(i);
	for(int j = 1; j < k; j++){
		int u = b[X[j]];
		int v = e[X[j]];
		int ru = findSet(u);
		int rv = findSet(v);
		if(ru == rv) return 0;
		link(ru, rv);
	}
	if(findSet(b[val]) == findSet(e[val])) return 0;
	return 1;
}

void TRY(int k){
	for(int v = X[k-1]; v <= M; v++){
		if(check(v, k)){
			X[k] = v;
			if(k == N-1){
				count += 1;
			}
			else{
			TRY(k+1);
			}	
		}
	}
}
void TRY(){
//	init();
	count = 0;
	X[0] = 1;
	TRY(1);
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
