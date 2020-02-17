#include "stdio.h"

#define T 31
#define S 21

int m;  		//staff
int n;  		//task
int k;			//max tasks performed by 1 staff
int c[S][T]; 		//c[i][j] is the cost staff i do task j

int load[S];		//load cua staff i
int totalCost;
int minium;
int min;

void input(){
	scanf("%d",&n);
	scanf("%d",&m);
	scanf("%d",&k);
	min = 10000;
	for(int i = 1; i <= m; i++){
		for(int j = 1; j <=n; j++){
			scanf("%d", &c[i][j]);
			if(c[i][j] < min) min = c[i][j];
		}
	}
}
void output(){
	printf("%ld\n", minium);
}
int check(int t, int s){
	if(load[s] >= k) return 0;
	
	return 1;
}
int checknhanhcan(int t){
	int tmp = totalCost + min*(n-t);
	if(tmp > minium) return 0;
	return 1;
}
void TRY(int t){
	if(checknhanhcan(t)){
		for(int s = 1; s <= m; s++){
			if(check(t,s)){
				load[s] += 1;
				totalCost += c[s][t];
				if(t == n) {
					if (totalCost < minium) minium = totalCost;
				}
				else{
					TRY(t+1);
				}
				totalCost -= c[s][t];
				load[s] -= 1;
			}
		}	
	}

}
void solve(){
	for (int i = 1; i <= n; i++){
		load[i] = 0;
	}	
	minium = 100000;
	totalCost = 0;
	TRY(1);
}

int main(){
	input();
	solve();
	output();
	return 0;
}
/*

6 2 3
2 5 7 7 2 9
9 8 9 4 8 5

*/
