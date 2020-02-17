#include "stdio.h"
#include "windows.h"


int main(){

	int n;
	int m;
	scanf("%d", &n);
	scanf("%d", &m);
	int a[n];
	for(int i = 0; i < n; i++){
		scanf("%d", &a[i]);
	}

	int sum = 0;
	int count = 0;
	int head = 0;
	int tail = 0;
   	for(int i = 0; i< n; i++){
   		for(int j = i; j < n; j++){
   			sum += a[j];
   			if(sum < m) count ++;
   			else if(sum == m){
   				count++;
   				break;
			}
		}
		sum = 0;	
	}
    printf("%d", count);
	return 0;
}
