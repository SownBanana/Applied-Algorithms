#include "stdio.h"
#define MAX 100

int n;
int x[MAX];
int appear[MAX];


int checkHV(int v, int k){
	return appear[v];
}


void solution(){
	for(int i = 1; i <= n; i++){
		printf("%d", x[i]);
	}
	printf("\n");
}
void TRY(int k){
	for(int v = 1; v<= n; v++){
		if(checkHV(k,v)){
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
