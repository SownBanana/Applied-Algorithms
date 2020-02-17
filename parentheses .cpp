#include "stdio.h"
#include "string.h"
int parentheses (char a[], int len){
	char stack[len];
	int top = 0;
	for(int i = 0; i < len; i++){
		if (a[i] == '(' ||a[i] == '['||a[i] =='{'){
			stack[top++] = a[i];
		}
		else if(a[i] == ')'){
			if(stack[top-1] == '('){
				top -= 1;
			}
			else return 0;
		}
		else if(a[i] == ']'){
			if(stack[top-1] == '['){
				top -= 1;
			}
			else return 0;
		}	
		else if(a[i] == '}'){
			if(stack[top-1] == '{'){
				top -= 1;
			}
			else return 0;
		}	
	}
	if(top != 0) return 0;
	return 1;
}

int main(){
	int n;
	scanf("%d", &n);
	n = n+1;
	char a[n][50];
	for(int i = 0; i < n; i++){
		gets(a[i]);
	}
	for(int i = 1; i < n; i++){
		printf("%d\n", parentheses(a[i], strlen(a[i])));
	}
	return 0;
}
