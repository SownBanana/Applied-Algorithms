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
//std::vector<int> d[MAX];	//d[a][b] is the upper bound of the length of the shortest path from s to v;
int node[MAX];  //node[i] is the ith element(vertex -u and weight -w) in th HEAP
int idx[MAX]; 	//idx[v] is the index of v in the HEAP (idx[node[i].u] = i) 
int sH; 		//size of HEAP	

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


int solve(){
	int rs = 0;
	for(int i = 0; i < k-1; i++){
		distance(r[i]);
		for(int j = i+1; j < k; j++){
//			std::cout<<"from "<<r[i]<<" to "<<r[j]<<" = "<<d[r[j]]<<std::endl;
			if(i!=j) {
				if(d[r[j]] > rs) rs = d[r[j]];
			}
		}
	}
	return rs;
}
int main(){
	input();
//	DFS();
	std::cout<<solve();
}

/*

6 10
1 2 2
1 5 6
1 6 1
2 3 8
2 6 4
3 4 7
3 6 2
4 5 3
4 6 5
5 6 4
6
1 2 3 4 5 6

*/
