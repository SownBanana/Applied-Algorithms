#include "stdio.h"
#define N 1000

int n;
int a[N];

void input(){
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		scanf("%d", &a[i]);
	}	
}

int solve(){
	int Q = 0;
	for(int i = 0; i < n; i++){
		for(int j = i+1; j < n; j++){
			if(a[i] < a[j]) Q++;
		}
	}
	return Q;
}
int main(){
	input();
	printf("%d", solve());
	return 0;
}


