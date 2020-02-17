#include "stdio.h"
#define P 1000000007
//a*b*c%P

long addmod(long a, long b){
    a = a%P;
    b = b%P;
    int tmp = P - a;
    if(tmp > b) return a+b;
    else return b - tmp;
}
long prodmod(long a, long b){
	long rs = 0;
	if(a<b){  
		int tmp = a;
		a = b;
		b = tmp;
	}
	while(b > 0){
		rs = addmod(rs, a);
		b--;
	}
	return rs;
}
int main(){
	printf("%d", prodmod(5, 4));
}

