#include "stdio.h"
 
int main(){
	int n;
	scanf("%d", &n);
	int a[n];
	for(int i = 0; i<n; i++){
		scanf("%d", &a[i]);
	}
	int i = 0;
	int s = 0;
	int tmp;
	int max = 0;
    while(i<n){
        tmp = s + a[i];
        if(tmp > 0) {
        	s = tmp;
        	if (tmp > max && tmp%2==0) max = tmp;
        	//b[index++] = tmp;
		}
        else if(tmp <= 0) s=0;
		i++; 
    }
 
    printf("%d", max);
	return 0;
}
