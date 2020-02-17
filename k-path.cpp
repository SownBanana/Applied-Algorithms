//#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <list>
#define MAX 100001
using namespace std;

typedef struct a{
	int u;
	int w1;
	int w2;
} pairWu;


int N,M,K,Q;
vector<pairWu> A[MAX];
int visited[MAX];
//int X[MAX];
int rs;
int sum1;
int sum2;
int index;
int minw1;
int minw2;

void input(){
	cin>>N>>M>>K>>Q;
	minw1 = 999;
	minw2 = 999;
	for(int i = 1; i <= M; i++){
		pairWu u;
		pairWu v;
		cin>>u.u>>v.u>>v.w1>>v.w2;
		u.w1 = v.w1; u.w2 = v.w2;
		A[u.u].push_back(v);
		A[v.u].push_back(u);
		if(v.w1 < minw1) minw1 = v.w1;
		if(v.w2 < minw2) minw2 = v.w2;
	}
}
 
void init(int i){
//	index = i;
	for(int v = 1; v <=N; v++) visited[v] = 0;
}
bool check(pairWu v, int k){
	if((sum1 + v.w1 + (K - k + 1)*minw1) > rs) return false;
	if((sum2 + v.w2 + (K - k + 1)*minw2) > Q) return false;
	return true;
}
void TRY(int k, int bef){
	for(int i = 0; i < A[bef].size(); i++){
		pairWu v = A[bef][i];
		if(!visited[v.u] && (sum2 + v.w2) <= Q && check(v, k)){
//			X[k] = v.u;
			visited[v.u] = 1;
			sum1 += v.w1;
			sum2 += v.w2;

			if(k == K+1){
//				for(int i = 1; i <= K+1; i++){
//					cout<<X[i]<<" ";
//				}
//			cout<<endl;				
				if(sum1 < rs){
					rs = sum1;
					
//					for(int i = 1; i <= K+1; i++){
//						cout<<X[i]<<" ";
//					}
//					cout<<"sum = "<<sum1;
//					
//					cout<<endl;
				}
			}
			else{
				TRY(k+1, v.u);
			}
			visited[v.u] = 0;
			sum1 -= v.w1;
			sum2 -= v.w2;	
		}
	}
}
void TRY(){	
	rs = 999999;
	for(int i = 1; i < N; i++){
		init(i);
		sum1 = 0;
		sum2 = 0;
//		X[1] = i;
		visited[i] = 1;
		TRY(2, i);	
	}
}
int main(){
	input();
	TRY();
	cout<<rs;
}
 /*
 
5 7 3 6
1 2 1 2
1 4 2 2
1 5 3 6
2 3 3 2
2 4 4 4
3 4 5 1
4 5 4 7
 
 */
