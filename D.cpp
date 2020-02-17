//#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <list>
#define MAX 21
using namespace std;

int N,M,s,L;
int b[MAX];				//begining
int e[MAX];				//ending

//int index[MAX]; index[b]

int c[MAX];
int l[MAX];

int r[MAX];         //rank
int p[MAX]; 		//p[v] is parent(root) of v

int X[MAX];

long long cost;
long long latency;

//int visited[MAX];

void input(){
	cin>>N>>M>>s>>L;
	for(int i = 1; i <= M; i++){
		cin>>b[i]>>e[i]>>c[i]>>l[i];
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
//void distance(int src, int dist){
//    priority_queue <ii, vector<ii>, greater<ii> > pq;
//    int i, u, v, du, uv;
//
//    for (i=1; i<=N; i++) d[i] = 99999;
//    d[src] = 0;
//    pq.push(ii(0, src));
//
//    while (pq.size()){
//        u=pq.top().second;
//        du=pq.top().first;
//        pq.pop();
//        if (du!=d[u]) continue;
//
//        for (i=0; v=A[u][i].second; i++)
//        {
//            uv=A[u][i].first;
//            if (d[v]>du+uv) {
//                d[v]=du+uv;
//                pq.push(ii(d[v], v));
//            }
//        }
//    }
//	return d[dist];
//}
//checkLatency(int k, int val){
//	if(distance(X[k]))
//}

void TRY(int k){
	long long rs = 999999999;
	for(int v = X[k-1]; v <= M; v++){
		if(check(v, k) && (latency + l[v])<L){
			X[k] = v;
			cost += c[v];
			latency += l[v];
			if(k == N-1){
				if(cost < rs) rs = cost;
			}
			else{
			TRY(k+1);
			}	
			cost -= c[v];
			latency -= l[v];
		}
	}
	return rs;
}
void TRY(){
//	init();
	cost = 0;
	latency = 0;
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
