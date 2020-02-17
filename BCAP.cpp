#include "stdio.h"

#define N 17
#define M 6

int n;		//courses
int m;		//periods
int credit[N];	//credits: c[i] is credit of course i
int A[N][N];	//prerequisites matrix: A[i][j] is course j must be assigned after course i in a period
//

int assigned[N];  	//assigned[i] is the period that course i is assigned in
int load[M]; 		//load of period i
int maxload;		//max load of all periods
int minium; 		//result

int minCredit;

void input(){
	minCredit = 1000000;
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++){
		scanf("%d", &credit[i]);
		if(credit[i] < minCredit) minCredit = credit[i];
	}
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			scanf("%d", &A[i][j]);
		}
	}
}
void output(){
	printf("%d", minium);
}
int checkCUT(int c, int p){
	float preLoad = load[p] + (n/(1.5*m))*minCredit;
	if (preLoad > minium) return 0;
	return 1;
}
int check(int c, int p){
	for(int i = 1; i <= n; i++){
		if(A[i][c] == 1){
			if(assigned[i] != 0 && assigned[i] != p) return 0;
		}
	}
	return 1;
}
int TRY(int c){
	for(int p = 1; p <= m; p++){
		if(check(c, p) && checkCUT(c,p)){
			assigned[c] = p;
			load[p] += credit[c];
			int tmp = maxload;
			if(load[p] > maxload) maxload = load[p];
			if(c == n){
				if(maxload < minium)
					minium = maxload;		
			}
			else{
				TRY(c+1);
			}
			maxload = tmp;
			load[p] -= credit[c];
			assigned[c] = 0;
		}
	}
}
void solve(){
	for(int i = 1; i <= n; i++){
		load[i] = 0;
	}
	for(int i = 1; i <= m; i++){
		assigned[i] = 0;
	}
	maxload = 0;
	minium = 1000000;
	TRY(1);
}
int main(){
	input();
	solve();
	output();
	return 0;
}
/*

6 2
4 4 4 4 2 4
0 0 0 0 0 0
0 0 0 0 0 0
0 0 0 0 0 0
0 0 1 0 0 0
0 0 1 0 0 0
1 0 0 0 0 0

*/

