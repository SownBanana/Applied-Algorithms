#include "stdio.h"
#define MAX 16
 
int n;
int appear[MAX];
int dist;
int map[MAX][MAX];
int rs;
int min;
int load;
int done[MAX];


int check(int v){
	return appear[v];
}
int check2(int v){
	for(int i = 1; i <= n; i++){
		if(i == v){
			if(load != 0){
			return 0;
			break;
			} 
		}	
	}
	return 1;
}
int check3(int v){
	int b;
    for(int i = 1; i <= n; i++){
    	if((i+n) == v) {
    		if(appear[i] == 1) return 0;
    		break;
		}
	}
	return 1;
}

int checkDone(){
	for(int i = 1; i <= n; i++){
		if(done[i] == 0) return 0;
	}
	return 1;
}
void solution(){
	printf("%d", rs);
}
void TRY(int bef, int k, int a){
	
	for(int v = a; v<= 2*n; v++){

		if(check(v) && check3(v) && check2(v)){
			appear[v] = 0;
			dist += map[bef][v];
			for(int i = 1; i <= n; i++){ //v la khach
				if(i == v){
					load += 1;
				}	
			}
			for(int i = 1; i <= n; i++){ // v la ben
				if((i + n) == v){
					load -= 1;
					done[i] = 1;
				}	
			}
			if(checkDone()){
				if(v == 0 && dist < rs) {
 					rs = dist;
				}
				else TRY(v, k+1, 0);
			}
			else{
				TRY(v, k+1, 1);
			}
			for(int i = 1; i <= n; i++){ // v la ben
				if((i + n) == v){
					load += 1;
					done[i] = 0;
				}	
			}
			for(int i = 1; i <= n; i++){ //v la khach
				if(i == v){
					load -= 1;
				}	
			}
			dist -= map[bef][v];
			appear[v] = 1;
		}
	}
}
void input(){
	min = 9999999;
	scanf("%d",&n);
	for(int i = 0; i <= 2*n; i++){
		for(int j = 0; j <= 2*n; j++){
			scanf("%d", &map[i][j]);
			if(map[i][j] < min && map[i][j] != 0) min = map[i][j];
		}
	}

}
int solve(){
	for(int i = 0; i < MAX; i++){
		appear[i] = 1;
	}
	for(int i = 0; i < MAX; i++){
		done[i] = 0;
	}
	dist = 0;
	rs = 9999;
	load = 0;
	TRY(0, 1, 1);
	solution();
}
int main(){
	input();
	solve();
	return 0;
}
