#include "stdio.h"
#define MAX 16
 
int n;
int k;
int appear[MAX];
int dist;
int map[2*MAX+1][2*MAX+1];
int rs;
int min;
int load;

int isPassenger(int v){
	for(int i = 1; i <= n; i++){
		if(i == v){
			return 1;
		}
	}
	return 0;
}
int isStation(int v){
	for(int i = 1; i <= n; i++){
		if(i+n == v){
			return 1;
		}
	}
	return 0;
}
int is_full_load(){
	if(load < k) return 0;
	return 1;
}
int check1(int v){ 				 //qua day chua
	return appear[v];
}
int check2(int v){ 				//con cho cho khach khong
	if(isPassenger(v)){
		if(is_full_load()){
			return 0;
		}
	}
	return 1;
}
int check3(int v){ 				//den ben V don khach V - n chua
	if(isStation(v)){
		if(appear[v-n] == 1) return 0;
	}
	return 1;
}
int check4(int k){              //cat nhanh can
	int g = dist + (2*n-k)*min;
	if (g > rs) return 0;
	return 1;
}
void solution(){
	printf("%d", rs);
}
void TRY(int bef, int k){
	
	for(int v = 1; v<= 2*n; v++){

		if(check1(v) && check3(v) && check2(v) && check4(v)){
			appear[v] = 0;
			dist += map[bef][v];
			if(isPassenger(v)) load++;
			if(isStation(v)){
				load--;
			}
			if(k==(2*n)){
				dist += map[v][0];
				if(dist < rs) rs = dist;
				dist -= map[v][0];
			}
			else{
				TRY(v, k+1);
			}
			if(isPassenger(v)) load--;
			if(isStation(v)){
				load++;
			}
			dist -= map[bef][v];
			appear[v] = 1;
		}
	}
}
void input(){
	min = 1000000;
	scanf("%d",&n);
	scanf("%d", &k);
	for(int i = 0; i <= 2*n; i++){
		for(int j = 0; j <= 2*n; j++){
			scanf("%d", &map[i][j]);
			if(map[i][j] < min && map[i][j] != 0) min = map[i][j];
		}
	}

}
int solve(){
	for(int i = 0; i < MAX; i++){    //1 chua qua 0 qua roi
		appear[i] = 1;
	}

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
