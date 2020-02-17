#include "stdio.h"
#include "windows.h"
char num1[6];
char num2[6];

int *enterNumber(char str[], int *n ){
	printf("Nhap so: ");
	gets(str);
	*n = strlen(str);
	int *rs = (int*)malloc((*n)*4);
	for(int i = 0; i < *n; i++){
		*(rs + i) = str[i] - 48;
	}
	
	return rs;
}
int *mult (int *a, int *b, int na, int nb){
	int n = na + nb;
	int ia = na;
	int ib = nb;
	int *rs = (int*)malloc(n*4);
	int rem;
	while (n>0 && ib>0){
		*(rs + n) = ((*(b + ib)) * (*(a + ia))+ rem)%10 ;
		rem = ((*(b + ib)) * (*(a + ia))+ rem)/10;
	}
	return rs;
}
int *cal (int *a, int *b, int na, int nb){
	int *rs = (int*)malloc(4*10);
	
	int ia = na;
	int ib = nb;
	
	while 
	return rs;
}
int main(){
	char c[6];
	int n;
	int *a = enterNumber(c, &n);
	int n;
	int *a = enterNumber(c, &n);
	for(int i = 0; i<n; i++){
		printf("%d", a[i]);
	}
	return 0;
}
