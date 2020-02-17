#include "stdio.h"
#define P 1000000007
//a^b%P
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
long expmod(long a,long b){
	if(b == 1) return a%P;
	long rs = expmod(a,b/2);
	rs = mulmod(rs,rs);
	if(b%2==0) return rs;
	else return mulmod(a,rs);
}

int main(){
    long a;
    long b; 
    long rs;
    scanf("%ld%ld",&a,&b);
	rs = expmod(a,b);
    printf("%ld", rs);
    return 0;
}
