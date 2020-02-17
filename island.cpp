#include "stdio.h"

#define MAX 1000

int n;		//_
int m;		//|
int A[MAX][MAX];

int island[MAX][MAX];	//island[i][j] is the island includes
int numberIsland;
int S[MAX];				//square of i island
int maxS;

void input(){
	scanf("%d", &n);
	scanf("%d", &m);
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			scanf("%d", &A[i][j]);
		}
	}
}
void output(){
	printf("%d\n%d", numberIsland, maxS);
//	for(int i = 1; i = numberIsland; i++){
//		printf("%d", S[i]);
//	}
}
int max(int pre){
	if(S[pre] > maxS) maxS = S[pre];
}
int check(int x, int y){
	int rs = -1;
	int pre = 0;
	int abo = 0;
	if(island[x-1][y] != 0) {
		int pre = island[x-1][y]; //previous
		rs = pre;
	}
	if(island[x][y-1] != 0) {
	 	int abo = island[x][y-1]; //above
	 	rs = abo;
	}
	if(pre*abo != 0 && pre != abo){
		S[pre] += S[abo];
		for(int i = 0; i <= y; i++){
			for(int j = 0; j < m; j++){
				if(island[i][j] == abo) island[i][j] = pre;
			}
		}
		numberIsland -= 1;
		rs = pre;
	}
	if(rs == -1) rs = ++numberIsland;
	S[rs] += 1;
	max(rs);
//	printf("S dao %d = %d", rs, maxS);
	return rs;
}
void TRY(){
	for(int x = 0; x < n; x++){
		for(int y = 0; y < m; y++ ){
			if(A[x][y] != 0){
				island[x][y] = check(x,y);
			}
		}
	}
}
void solve(){
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			island[i][j] = 0;
		}
	}
	for (int i = 1; i < MAX; i++){
		S[i] = 0;
	}
	numberIsland = 0;
	maxS = 0;
	TRY();
}
int main(){
	input();
	solve();
	output();
}	
/*

7 11
0 0 0 0 0 0 0 0 0 1 0
1 1 1 0 0 0 0 0 0 0 0
0 0 0 0 0 1 1 1 1 0 0
0 0 1 1 1 1 1 1 1 1 0
0 0 1 1 1 1 1 1 1 1 0
0 0 1 1 1 1 1 1 0 0 0
0 0 0 0 0 1 1 0 0 0 0

*/	

