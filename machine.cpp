#include "stdio.h"

#define MAX 1000000

typedef struct period{
	int s;
	int t;
	int amount;
} period;

int n;
period p[MAX];



void swapC(int x, int y){
	period tmp = p[x];
	p[x] = p[y];
	p[y] = tmp;
}
int partition(int l, int r, int pivotIndex){
	int pivot = p[pivotIndex].amount;
	int index = l;
	swapC(pivotIndex, r);
	for(int i = l; i<r; i++){
		if(p[i].amount<pivot){
			swapC(i,index++);
		}
	}
	swapC(index, r);
	return index;
}

void quicksort(int l, int r){
	if(l<r){
		int pivotIndex = (l+r)/2;
		int index = partition(l, r, pivotIndex);
		quicksort(l, index-1);
		quicksort(index + 1, r);
	} 
}

void input(){
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		scanf("%d%d", &p[i].s, &p[i].t);
		p[i].amount = p[i].t - p[i].s;
	}
}

int solve(){
//	for(int i = 0; i < n; i++){
//		for(int j = n - 1; j > i; j--){
//			if(p[i].t > p[j].s) break;
//			if(max < p[i].amount + p[j].amount) max = p[i].amount + p[j].amount;
//		}
//	}
	for(int i = n - 1; i >= 0; i--){
		for(int j = i - 1; j >=0; j--){
			if(p[i].t < p[j].s || p[j].t < p[i].s) {
				return p[i].amount + p[j].amount;
			}
		}
	}
}

int main(){
	input();
	quicksort(0, n-1);
	
	printf("%d", solve());
}

/*

5
8 12
6 11
3 9
2 5
1 4

*/
