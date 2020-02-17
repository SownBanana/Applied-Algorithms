#include "stdio.h"
#define MAX 100
 
int n;
int cap;
int appear[2*MAX];
int dist;
int map[2*MAX+1][2*MAX+1];
int rs;
int min;
int load;


int check4(int k){              //cat nhanh can
	int g = dist + (2*n + 1 - k)*min;
	if (g > rs) return 0;
	return 1;
}

int check(int v){
	if(appear[v] == 0) return 0;
	if(v > n) {
		if(appear[v-n]) return 0;
	}
	else if (load + 1 > cap ) return 0;
	return 1;
}

void solution(){
	printf("%d", rs);
}
void TRY(int bef, int k){
	
	for(int v = 1; v<= 2*n; v++){

		if(check(v) && check4(v)){
			appear[v] = 0;
			dist += map[bef][v];
			if(v <= n)
				load++;
			else
				load--;

			if(k==(2*n)){
				dist += map[v][0];
				if(dist < rs) rs = dist;
				dist -= map[v][0];
			}
			else{
					TRY(v, k+1);
				}
			if(v <= n)
				load--;
			else
				load++;
			dist -= map[bef][v];
			appear[v] = 1;
		}
	}
}
void input(){
	min = 1000000;
	scanf("%d",&n);
	for(int i = 0; i <= 2*n; i++){
		for(int j = 0; j <= 2*n; j++){
			scanf("%d", &map[i][j]);
			if(map[i][j] < min && i!=j) min = map[i][j];
		}
	}
}
int solve(){
	for(int i = 0; i < 2*MAX; i++){    //1 chua qua 0 qua roi
		appear[i] = 1;
	}
	cap = 1;
	dist = 0;
	rs = 1000000;
	load = 0;
	TRY(0, 1);
	solution();
}
int main(){
	input();
	solve();
	return 0;
}
