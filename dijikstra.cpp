#include <iostream>
#include <vector>
#include <list>
#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;
#define MAX 2000001
 

typedef pair<int, int> ii;

int N,M,k;

vector<ii> A[MAX];		//tree

int r[MAX];
int p[MAX];
bool fixed[MAX];

//heap
int d[MAX];		//d[v] is the upper bound of the length of the shortest path from s to v;

void input(){
	std::cin>>N>>M;
	for(int i = 0; i < M; i++){
		int p, q, w;
		scanf("%d%d%d", &p, &q, &w);
        A[p].push_back(ii(w, q));
        A[q].push_back(ii(w, p));
	}
	std::cin>>k;
	for(int i = 0; i <k; i++){
		std::cin>>r[i];
	}
	for (int i=1; i<=N; i++) A[i].push_back(ii(0,0));
}
 
void distance(int src){
    priority_queue <ii, vector<ii>, greater<ii> > pq;
    int i, u, v, du, uv;

    for (i=1; i<=N; i++) d[i] = 99999;
    d[src] = 0;
    pq.push(ii(0, src));

    while (pq.size()){
        u=pq.top().second;
        du=pq.top().first;
        pq.pop();
        if (du!=d[u]) continue;

        for (i=0; v=A[u][i].second; i++)
        {
            uv=A[u][i].first;
            if (d[v]>du+uv) {
                d[v]=du+uv;
                pq.push(ii(d[v], v));
            }
        }
    }

}
