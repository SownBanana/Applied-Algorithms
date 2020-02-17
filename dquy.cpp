#include "stdio.h"
#define M 5
int T;
int check(int k, int v, int n, int x[]){
	T+=v;
	if(k == n) return T == M;
	else return T < M;
}
int solution(int n, int x[]){
	for(int i = 0; i < n; i++){
		printf("%d ", x[i]);
	}
	printf("\n");
}
void TRY(int k, int n, int x[]){
	for(int v = 1; v <= M - T - (n-k); v++){
		if(check){
			x[k-1] = v;
			T += v;
			if(k == n) solution(n,x);
			else {
				TRY(k+1, n, x);
			}
			T -= v;
		}
	}
}

int main(){
	T = 0;
	int n;
	scanf("%d", &n);
	int x[n];
	TRY(0,n,x);
}
