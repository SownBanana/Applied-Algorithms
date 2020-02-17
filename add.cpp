#include "stdio.h"
#include "windows.h"
char num1[19];
char num2[19];

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
//int *add(int *n1, int *n2, int na, int nb){
//	int n;
//	int l1;
//	int l2;
//	int *a;
//	int *b;
//	if(na >= nb){
//		n = na;
//		l1 = na;
//		l2 = nb;
//		*a = *n1;
//		*b = *n2;
//	}
//	else {
//		n = nb;
//		l1 = nb;
//		l2 = na;
//		*a = *n2;
//		*b = *n1;
//	}
//	int * rs = (int*)calloc(n,4);
//	int ia = l1;
//	int ib = l2;
//	int rem = 0;
//	while (n >= 0 && ib >= 0){
//		*(rs + n) = ((*(b + ib)) + (*(a + ia))+ rem)%10;
//		rem = ((*(b + ib)) + (*(a + ia))+ rem)/10;
//		n--;
//		ia--;
//		ib--;
//	}
//	while (ia >= 0){
//		*(rs + n) = (*(b+ib)+rem)%10;
//		rem = (*(b+ib)+rem)/10;
//	}
//	return rs;
//}
int *add(int *a, int *b, int na, int nb){
	printf("a = ");
	for(int i = 0; i<na; i++){
		printf("%d", *(a+i));
	}
	printf("\n");
	printf("b = ");
	for(int i = 0; i<nb; i++){
		printf("%d", *(b+i));
	}
	printf("\n");
	int n = na;
	int * rs = (int*)calloc(n,4);
	int ia = na;
	int ib = nb;
	int rem = 0;
	int sum;
	while (n > 0 && ib > 0){
		n--;
		ia--;
		ib--;
		printf("%d, %d, %d", n, ia, ib);
		printf("\n");
		sum = (*(b + ib)) + (*(a + ia))+ rem;
		*(rs + n) = sum%10;
		printf("=%d\n", *(rs+n));
		rem = sum/10;
		printf("du %d\n", rem);
	
	}
	while (ia > 0){
		ia--;
		*(rs + n) = (*(a+ia)+rem)%10;
		printf("=%d\n", *(rs+n));
		rem = (*(a+ia)+rem)/10;
		printf("du %d\n", rem);
	}
	for(int i = 0; i<=na; i++){
		printf("%d", rs[i]);
	}
	return rs;
}
int main(){
	char ca[6];
	char cb[6];
	ca[5] = '\0';
	cb[5] = '\0';
	int na;
	int *a = enterNumber(ca, &na);
	int nb;
	int *b = enterNumber(cb, &nb);
	int *c = add(a, b, na, nb);
//	for(int i = 0; i<=na; i++){
//		printf("%d", c[i]);
//	}
	return 0;
}
