#include <stdio.h>

#define MAX 10001
int n;
int m;
int x[MAX];				//First Array
int y[MAX];				//Second Array
int S[MAX][MAX];

int max(int a, int b){
	return (a>b)?a:b;
}
int find(){
	int rs = 0;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			if(x[i] == y[j]){
				S[i][j] = S[i-1][j-1] + 1;
			}
			else{
				S[i][j] = max(S[i][j-1],S[i-1][j]);
			}
			if(rs < S[i][j]) rs = S[i][j];
		}
	}
	return rs;
}
void input(){
	scanf("%d", &n);
	scanf("%d", &m);
	for(int i = 1; i <= n; i++){
		scanf("%d", &x[i]);
	}
	for(int i = 1; i <= m; i++){
		scanf("%d", &y[i]);
	}
	for(int i = 0; i <= m; i++){
		S[0][i] = 0;
	}
	for(int i = 1; i <= n; i++){
		S[i][0] = 0;
	}
}

int main(){
	input();
	printf("%d\n", find());
}
/*
7 10
3 7 2 5 1 4 9
4 3 2 3 6 1 5 4 9 7
*/

