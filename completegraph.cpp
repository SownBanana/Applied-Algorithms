#include <iostream>
using namespace std;

#define MAX 1001

int N; //N dinh, M canh
int A[MAX][MAX];

void input(){
	cin>>N;
	for(int i = 1; i <= N; i++){
		for(int j = 1; j <=N; j++){
			cin>>A[i][j];	
		}	
	}
}
void printGraph(){
	for(int i = 1; i <= N; i++){
		for(int j = 1; j <=N; j++){
			cout<<A[i][j]<<" ";	
		}
		cout<<endl;	
	}
}
int solve(){
	for(int i = 1; i <= N; i++){
		if(A[i][i] != 0) return 0;
		for(int j = 1; j <=N; j++){
			if((j != i) && (A[i][j] == 0)) return 0;
		}	
	}
	return 1;
}
int main(){
	input();
//	printGraph();
	cout<<solve();
}

