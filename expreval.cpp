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
	int rs = 0;
	for(int i = 0; i < n-1; i++){
		if(b[i] == 2){
			int tmp = mulmod(a[i], a[i+1]);
			b[i] = 3;
			int itmp = i+1;
			while(b[itmp] == 2){
				tmp = mulmod(tmp, a[itmp + 1]);
				b[itmp] = 3;
				itmp++;
			}
			if(b[i-1] == 0) rs = addmod(rs, -tmp);
			else rs = addmod(rs, tmp);
			b[i-1] = 3;
		}		
	}	
	rs += a[0];
	for(int i = 0; i < n - 1; i++){
		if(b[i] == 0) rs = addmod(rs, -a[i+1]);
		else if (b[i] == 1) rs = addmod(rs, a[i+1]);
	}
	return rs;
}

int main(){
	input();
	printf("%d", solve());
	return 0;
}
