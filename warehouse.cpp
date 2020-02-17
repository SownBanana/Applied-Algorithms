#include <stdio.h>

#define N 1000
#define maxT 101


int n;
int T;
int D;
int	a[N];
int t[N];

int F[N][maxT];

int max(int a, int b){
	return (a>b)?a:b;
}
int min(int a, int b){
	return (a<b)?a:b;
}
int find(){
	int rs = 0;
	for(int i = 1; i < n; i++){
		for(int d = 0; d <= T; d++){
			for(int j = max(i - D,0); j < i; j++){
				int tsau = d - t[i];
				if(tsau >= 0 && F[j][tsau] >= 0){
					if(F[i][d] < F[j][tsau] + a[i] ) {
						F[i][d] = F[j][tsau] + a[i];
//						printf("F[%d][%d] = %d = Ftr[%d][%d] + %d\n", i, d, F[i][d], j, tsau, a[i]);
					}
				}
			}
			if(rs < F[i][d]) rs = F[i][d];
		}
	}
	return rs;
	
}

void input(){
	scanf("%d%d%d", &n, &T, &D);
	for(int i = 0; i < n; i++){
		scanf("%d", &a[i]);
	}
	for(int i = 0; i < n; i++){
		scanf("%d", &t[i]);
	}
	for(int i = 0; i < n; i++){
		for(int d = 0; d <= T; d++){
			F[i][d] = -1;
		}			
		F[i][t[i]] = a[i];
	}

}

int main(){
	input();
	printf("%d", find());	
	}

/*
6 6 2
6 8 5 10 11 6
1 2 2 3 3 2
*/

