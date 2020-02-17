#include <iostream>
#include <vector>
#include <queue>
#define MAX 100001
using namespace std;
int N,M;
vector<int> A[MAX];
int side[MAX]; 

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
	for(int i = 1; i <= N; i++){
		side[i] = -1;
	}
}
bool checkSameSide(int u, int v){
	if(side[u]%2 == side[v]%2) return true;
	else return false;
}
int BFS(int u){
	queue<int> Q;
	Q.push(u);
	side[u] = 0;
	while(!Q.empty()){
		int v = Q.front();
		Q.pop();
		for(int i = 0; i < A[v].size(); i++){
			int x = A[v][i];
			if(side[x] > -1){
				if(checkSameSide(x, v)) return 0;
			}
			else{
				side[x] = side[v] + 1;
				Q.push(x);
			}
		}
	}
	return 1;
}
int BFS(){
	init();
	return BFS(1);
}
int main(){
	input();
	cout<<BFS();
}

/*

6 6
1 2
1 3
2 5
2 6
4 5
4 6

*/
