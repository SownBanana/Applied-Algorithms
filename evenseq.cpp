#include "stdio.h"
#include "windows.h"
#define N 100000

int n;
int a[N];
int S[N][2];	//S[head][0] max even
				//S[head[1] max odd


void input(){
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		scanf("%d", &a[i]);
		if(a[i]%2 == 0) {
			S[i][0] = a[i];
			S[i][1] = -1000000;
		}
		else {
			S[i][1] = a[i];
			S[i][0] = -1000000;
		}
	}
//	for(int i = 0; i <n; i++){
//		printf("%d. S0 = %d, S1 = %d\n", i, S[i][0], S[i][1]);
//	}

}
int solve(){
	int rs = -1000000;
	for(int i = 1; i < n; i++){
		for(int t = 0; t < 2; t++){
			int tmp = S[i-1][t] + a[i];
//			printf("%d ", tmp);
//			printf("duw %d ", tmp%2);
			if(tmp%2 == 0 && tmp > S[i][0])	S[i][0] = tmp;
			else if(tmp%2 != 0 && tmp > S[i][1]) S[i][1] = tmp;
		}
		if(S[i][0] > rs) rs = S[i][0];
	}
//	for(int i = 0; i <n; i++){
//		printf("%d. S0 = %d, S1 = %d\n", i, S[i][0], S[i][1]);
//	}
	return rs;
}
int main(){
	input();
	printf("%d", solve());
}
