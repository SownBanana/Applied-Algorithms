#include "stdio.h"

#define C 21
#define T 6

int m;  		//teacher
int n;  		//courses
int h[C]; 		//courses duration
int pref[C][T];	//mon co the day
int conf[C][C];		//mon ko dang ky cung nhau

int assigned[C];	//mon da dang ky
int load[T];
int maxload;
int minium;
//int teached[T][C];

void input(){
	scanf("%d",&m);
	scanf("%d",&n);
	for(int i = 1; i <= m; i++){
		scanf("%d", &h[i]);
	}
	for(int i = 1; i <= m; i++){
		scanf("%d", &pref[i][0]);
		for(int j = 1; j <= pref[i][0]; j++){
			scanf("%d", &pref[i][j]);
		}
	}
	for(int i = 1; i <= m; i++){
		for(int j = 1; j <= m; j++){
			scanf("%d", &conf[i][j]);
		}
	}
}
void output(){
	printf("%d\n", minium);
}
int check(int c, int t){
	int check = 0;
	for(int i = 1; i <= pref[c][0]; i++){		//co thich day khong
		if(pref[c][i] == t) check = 1;
	}
	for(int i = 1; i<= m; i++){
		if(conf[c][i] == 1){
			if(assigned[i] == t)  return 0;
		}
	}
	if(check)
		return 1;
}
void TRY(int c){
	for(int t = 1; t <= n; t++){
		if(check(c,t)){
			assigned[c] = t;
			load[t] += h[c];
			int temp = maxload;
			if(load[t] > maxload) maxload = load[t];
			if(c == m) {
				if (maxload < minium) minium = maxload;
			}
			else{
				TRY(c+1);
			}
			maxload = temp;
			assigned[c] = 0;
			load[t] -= h[c];
		}
	}
}
void solve(){
	for (int i = 1; i <= m; i++){
		assigned[i] = 0;
	}
	for (int i = 1; i <= n; i++){
		load[i] = 0;
	}	
	minium = 1000000;
	maxload = 0;
	TRY(1);
}

int main(){
	input();
	solve();
	output();
	return 0;
}
/*

4 2
3 7 2 1
2 1 2
2 1 2
2 1 2
2 1 2
0 0 0 1
0 0 0 0
0 0 0 1
1 0 1 0

*/
