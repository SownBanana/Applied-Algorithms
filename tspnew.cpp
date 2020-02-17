#include "stdio.h"
#define MAX 16
 
int n;
int x[MAX];
int appear[MAX];
int dist;
int map[MAX][MAX];
int rs;
int min;
int check(int v){
	return appear[v];
}
int check2(int k){
	int g = dist + (n+1-k)*min;
	if (g > rs) return 0;
	return 1;
}
 
void solution(){
//	for(int i = 0; i <= n; i++){
//		printf("%d", x[i]);
//	}
//	printf("disct = %d\n", dist);
	printf("%d", rs);
}
void TRY(int bef, int k){
	for(int v = 1; v<= n; v++){
		if(check(v) && check2(k)){
			x[k] = v;
			appear[v] = 0;
			dist += map[bef][v];
			if(k == n) {
				dist += map[v][0];
				if(dist < rs) rs = dist;
				dist -= map[v][0];
			}
			else{
				TRY(v, k+1);
			}
			dist -= map[bef][v];
			appear[v] = 1;
		}
	}
}
void input(){
	min = 1000000;
	scanf("%d",&n); 
	for(int i = 0; i <= n; i++){
		for(int j = 0; j <= n; j++){
			scanf("%d", &map[i][j]);
			if(map[i][j] < min && map[i][j] != 0) min = map[i][j];
		}
//		printf("\n");
	}

}
int solve(){
	for(int i = 0; i < MAX; i++){
		appear[i] = 1;
	}
	dist = 0;
	rs = 1000000;
	TRY(0, 1);
	solution();
}
int main(){
	input();
	solve();
	return 0;
}
