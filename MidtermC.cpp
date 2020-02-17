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

	int s = 0;
	int count = 0;
	int head = 0;
	int tail = 0;
    while(tail < n){
        s += a[tail];
        if(s == m) {
        	count++;
        	s = 0;
        	head = head+1;
        	tail = head;
		}
		else if(s < m) {
			count++;
			tail++;
		}
		else{
			s = 0;
        	head = head+1;
        	tail = head;
		} 
    }
    printf("%d", count);
	return 0;
}
