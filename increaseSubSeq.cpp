#include <stdio.h>

int n;
int a[10000];
int S[10000];

int find(int pos){
	S[0] = 1;
	int rs = S[0];
	for(int i = 1; i <= pos; i++){
		S[i] = 1;
		for(int j = 0; j < i; j++){
			if(a[i] > a[j] && S[i] < S[j]+1) S[i] = S[j] + 1;
		}
		if(rs < S[i]) rs = S[i];
	}
	return rs;
}
void input(){
	scanf("%d", &n);
	for(int i = 0; i< n; i++){
		scanf("%d", &a[i]);
		S[i] = 0;
	}
}

int main(){
	input();
	printf("%d", find(n-1));
}
