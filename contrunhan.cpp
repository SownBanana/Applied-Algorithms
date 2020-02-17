#include "stdio.h"
#define N 200000
#define P 1000000007
int n;
int a[N];
int b[N];

long addmod(long a, long b){
    a = a%P;
    b = b%P;
    int tmp = P - a;
    if(tmp > b) return a+b;
    else return b - tmp;
}
long mulmod(long a, long b){
	if(a == 1) return b%P;
	if(b == 1) return a%P;
	if(a<b){  
		int tmp = a;
		a = b;
		b = tmp;
	}
	//b<a
	long rs = mulmod(a,b/2);
	rs = addmod(rs,rs);
	if(b%2==0) return rs;
	else return addmod(a,rs);
}

int input(){
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		scanf("%d", &a[i]);
	}
	for(int i = 0; i < n-1; i++){
		scanf("%d", &b[i]);
	}
}

int solve(){
	long rs = a[0];
	int i = 0;
	while(i <= n-1){
		
//		printf("%d, rs = %d\n",i, rs);
		if(b[i] == 0) {
			rs = addmod(rs, -a[i+1]);
//			printf("ok-\n");
			i++;
		}
		else if(b[i] == 1) {
			rs = addmod(rs, a[i+1]);
//			printf("ok+\n");
			i++;
		}
		else {
//			printf("ok*\n");
			if(b[i-1] == 1){
				rs = addmod(rs, -a[i]);
				int tmp = mulmod(a[i], a[i+1]);
				i = i+1;
//				printf("%d %d\n", b[i], b[i+1]);
				while(b[i] == 2){
					tmp = mulmod(tmp, a[i + 1]);
					i++;
//					printf("%d\n", i);
				}
				rs = addmod(rs, tmp);
			}
			if(b[i-1] == 0){
				rs = addmod(rs, a[i]);
				int tmp = mulmod(a[i], a[i+1]);
				int i = i+1;
				while(b[i] == 2){
					tmp = mulmod(tmp, a[i + 1]);
					i++;
					printf("%d\n", i);
				}
				rs = addmod(rs, -tmp);
			}			
		}
	}
	return rs;
}

int main(){
	input();
	printf("%ld", solve());
	return 0;
}
