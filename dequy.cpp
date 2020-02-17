#include "stdio.h"
#define MAX 100

int n;
int x[MAX];
int appear[MAX];

int check11(int v, int k){
	if(x[k-1] == 1) return 0;
	else return 1;
}

int check(int v, int k){
	return appear[v];
}
void solution(){
	for(int i = 1; i <= n; i++){
		printf("%d", x[i]);
	}
	printf("\n");
}
void TRY(int k){
	for(int v = 0; v<= 1; v++){
		if(1){
			x[k] = v;
			appear[v] = 0;
			if(k == n) solution();
			else{
				TRY(k+1);
			}
			appear[v] = 1;
		}
	}
}
void input(){
	scanf("%d",&n);
}
int solve(){
	for(int i = 0; i < MAX; i++){
		appear[i] = 1;
	}
	TRY(1);
}
int main(){
	input();
	solve();
}
