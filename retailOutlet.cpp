#include "stdio.h"

#define N 101
#define M 501
#define P 1000000007;


int n;		//number of branches
int m;		//number of retail outlets
int a[N];	//a[i] is number of salesmen of branch i


int S[N][M];

int max(int a, int b){
	return (a>b)?a:b;
}
int addmod(int a, int b){
    a = a%P;
    b = b%P;
    int tmp = P - a;
    if(tmp > b) return a+b;
    else return b - tmp;
}

int input(){
	scanf("%d%d", &n, &m);
	for(int i = 0; i < n; i++){
		scanf("%d", &a[i]);
	}

	for(int i = 0; i < n; i++){
		for( int j = 1; j <= m; j++){
			S[i][j] = -1;
		}
	}

	

}

int solve(){
	for(int k = 1; k <= m; k++){
		if(k%a[0] == 0) S[0][k] = 1;
		else S[0][k] = 0;
	}
	int T = a[0];
	for(int i = 1; i < n; i++){
		T += a[i];
		for(int k = 1; k <= m; k++){
			int ub = (k - T)/a[i];
			S[i][k] = 0;
			for(int v = 1; v <= ub; v++){
				if(S[i-1][k - a[i]*v] > -1)
				S[i][k] = addmod(S[i][k], S[i-1][k - a[i]*v]);
			}
//			printf("S[%d][%d] = %d\n", i,k,S[i][k]);
		}
	}
	return S[n-1][m];
	
}
int main(){
	input();
	printf("%d", solve());
}



/*

2 20
3 2

*/


