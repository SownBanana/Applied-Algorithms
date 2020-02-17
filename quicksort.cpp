#include "stdio.h"

void swap(int &a, int &b){
	int temp;
	temp = a;
	a = b;
	b = temp;
}
int partition(int a[], int l, int r, int pivotIndex){
	int pivot = a[pivotIndex];
	int index = l;
	swap(a[pivotIndex], a[r]);
	for(int i = l; i<r; i++){
		if(a[i]<pivot){
			swap(a[i],a[index++]);
		}
	}
	swap(a[index], a[r]);
	return index;
}

void quicksort(int a[], int l, int r){
	if(l<r){
		int pivotIndex = (l+r)/2;
		int index = partition(a, l, r, pivotIndex);
		quicksort(a, l, index-1);
		quicksort(a, index + 1, r);
	} 
}

int main(){
	int n;
	scanf("%d", &n);
	int a[n];
	for(int i = 0; i < n; i++){
		scanf("%d", &a[i]);
	}
	quicksort(a, 0, n-1);
	for(int i = 0; i < n; i++){
		printf("%d ", a[i]);
	}
}
