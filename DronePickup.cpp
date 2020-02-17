#include <stdio.h>

#define MAX 3000
#define Km 101
int n;
int K;
int	c[MAX];
int a[MAX];
int F[MAX][Km];

int max(int a, int b){
	return (a>b)?a:b;
}
int min(int a, int b){
	return (a<b)?a:b;
}
int find(){
	int rs = 0;
	F[0][0] = c[0];	
	for(int i = 1; i < n; i++){
		for(int k = 1; k < K; k++){
			for(int j = 0; j < i - 1; j++){
				if(F[j][k-1] > 0 && (j + a[j] >= i)){
					if ((F[i][k] < F[j][k - 1] + c[i])) F[i][k] = F[j][k - 1] + c[i];									
				}
			}
			if(rs < F[i][k]) rs = F[i][k];
			printf("\n");	
	for(int i = 0; i < n; i++){
		printf("%d ", F[i][K-3]);
	}
	printf("\n");
	for(int i = 0; i < n; i++){
		printf("%d ", F[i][K-2]);
	}
	printf("\n");
	for(int i = 0; i < n; i++){
		printf("%d ", F[i][K-1]);
	}
		}
	}
	return rs;
}

void input(){
	scanf("%d", &n);
	scanf("%d", &K);
	for(int i = 0; i < n; i++){
		scanf("%d", &c[i]);
	}
	for(int i = 0; i < n; i++){
		scanf("%d", &a[i]);
	}
	for(int i = 0; i < n; i++){
		for (int j = 1; j < K; j++){
			F[i][j] = -1;
		}
	}
	for(int i = 0; i < n; i++){
		F[i][0] = c[i];
	}
				printf("\n");	
	for(int i = 0; i < n; i++){
		printf("%d ", F[i][K-3]);
	}
	printf("\n");
	for(int i = 0; i < n; i++){
		printf("%d ", F[i][K-2]);
	}
	printf("\n");
	for(int i = 0; i < n; i++){
		printf("%d ", F[i][K-1]);
	}
}

int main(){
	input();
	printf("%d\n", find());
	printf("\n");	
	for(int i = 0; i < n; i++){
		printf("%d ", F[i][K-3]);
	}
	printf("\n");
	for(int i = 0; i < n; i++){
		printf("%d ", F[i][K-2]);
	}
	printf("\n");
	for(int i = 0; i < n; i++){
		printf("%d ", F[i][K-1]);
	}

}
/*
6 3
3 1 4 2 2 2
2 3 1 1 3 1
*/

