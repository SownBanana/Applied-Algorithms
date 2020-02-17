#include <stdio.h>

#define MAX 100000
int n;
int L1;
int L2;
int a[MAX];
int S[MAX];
int B;
int max(int a, int b){
	return (a>b)?a:b;
}
int min(int a, int b){
	return (a<b)?a:b;
}
int find(){
	int rs = 0;
//	for(int i = 0; i < L1;i++){
//		S[i] = a[i];
//	}	
	for(int i = 0; i < n; i++){
		S[i] = a[i];
		for(int j = max(0, i - L2); j <= min(i - L1, i - 1); j++){
			if(S[i] < S[j] + a[i]) S[i] = S[j] + a[i];
		}
		if(rs < S[i]) rs = S[i];
	}
	return rs;
}
int findTL(int pos){
	if(pos < 0) return 0;
	int check = 0;
	for(int i = 0; i < B; i++){
		if(pos == i) check = 1;
	}
	if(check){
		S[pos] = a[pos];
		return S[pos];
	}
	int maxvalue = 0;
	for(int i = L1; i <= L2; i++){
		int tmp = findTL(pos - i) + a[pos];
		if(maxvalue < tmp) maxvalue = tmp;
	}
	S[pos] = maxvalue;
	return S[pos];
	
}
void input(){
	scanf("%d", &n);
	scanf("%d", &L1);
	scanf("%d", &L2);
	B = L2 - L1 + 1;
	for(int i = 0; i < n; i++){
		scanf("%d", &a[i]);
		S[i] = 0;
	}
}

int main(){
	input();
	printf("%d\n", find());
//	for(int i = 0; i < n; i++){
//		printf("%d ", S[i]);
//	}
}
/*
6 2 3
3 5 9 6 7 4

10 2 4
3 5 9 6 7 4 5 9 3 2
*/

