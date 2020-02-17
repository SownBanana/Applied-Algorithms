#include "stdio.h"
#include <stdlib.h>
#define N 100
#define P 1000000007

int n;
int b;
int a[N];
int maxa;
int sum;
int count;

long addmod(long a, long b){
    a = a%P;
    b = b%P;
    int tmp = P - a;
    if(tmp > b) return a+b;
    else return b - tmp;
}

void input(){
	maxa = -101;
	scanf("%d", &n);
	scanf("%d", &b);
	for(int i = 0; i < n; i++){
		scanf("%d", &a[i]);
		if(abs(a[i]) > maxa) maxa = abs(a[i]);
	}
}
int check(int k, int sum){
//	printf("k=%d , abssum = %d ", k, abs(sum));
	if(abs(sum) - (n-k+2)*maxa > 12) {
//		printf("loai sum = %d\n", abs(sum));
		return 0;	
	}
	return 1;
}
void TRY(int k){
//		int tmp = sum;
			
		for(int o = 0; o < 2; o++){
			if(check(k, sum)){
				if(o == 0) sum = addmod(sum, -a[k]);
				else sum = addmod(sum, a[k]);
//				printf("%d\n", sum);
				if(k == n-1){
					if(sum == b) count += 1;
				}
				else{
					TRY(k+1);
				}
				if(o == 0) sum = addmod(sum, a[k]);
				else sum = addmod(sum, -a[k]);
		}
	}
}

void solve(){
	count = 0;
	sum = a[0];
	TRY(1);
}

int main(){
	input();
	solve();
	printf("%d", count);
	return 0;
}
