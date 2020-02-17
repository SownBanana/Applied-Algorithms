#include <iostream>
#include <stack> 
#include<set>
using namespace std;

#define MAX 100001

int N, M; //N dinh, M canh
set<int> A[MAX];

void input(){
	cin>>N>>M;
	int v;
	int u;
	for(int i = 1; i <= M; i++){
		cin>>v>>u;
		A[v].insert(u);
		A[u].insert(v);
	}
}
void printGraph(){
//	for(int v = 1; v <= N; v++){
//		cout<<"A["<<v<<"] = ";
//		for(set<int)::iterator it = A[v].begin(); it != A[v].end(); it++){
//			int x = *it;
//			cout<<x<<" ";
//		} 
//		cout<<endl;
//	}
}

int solve(){
	stack<int> S;
	stack<int> CE;
	S.push(1);
	while(!S.empty()){
		int x = S.top();
		if(!A[x].empty()){
			int y = *(A[x].begin());
			S.push(y);
			A[x].erase(y);
			A[y].erase(x);
		}else{
			S.pop();
			CE.push(x);
		}
	}
	cout<<"Euler: ";
	while(!CE.empty()){
		int x = CE.top();
		CE.pop();
		cout<<x<<" ";
	}
}
int main(){
	input();
	printGraph();
	solve();
}
