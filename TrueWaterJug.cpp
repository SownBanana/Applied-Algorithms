#include "stdio.h"
#include "string.h"
#include "windows.h"

int checkvisit[1100][1100];
int head;
int tail;
int check;

typedef struct stt{
	int x;
	int y;
	int step;
}stt;

stt initStt ( int a, int b, int step){
	stt s;
	s.x = a;
	s.y = b;
	s.step = step;
	return s;
}

stt* q;


stt dequeue (){
	head += 1;
	return q[head-1];
}
stt pop (){
	return q[head];
}
void enqueue (stt a){
	*(q+tail) = a;
	tail += 1;
}
int checkWater(stt q[], int c){
	stt p = pop();
	printf("x = %d, y = %d, step = %d\n", p.x, p.y, p.step);
	
	if(p.x == c || p.y == c) return p.step;
	checkvisit[p.x][p.y] = 1;
	return -1;
}
void waterJug (/*stt q[], */int a, int b){
	stt curr = dequeue();
	//x<a -> fill a
	if(curr.x < a){
		stt p = initStt(a, curr.y, curr.step + 1);
		if(checkvisit[p.x][p.y] == 0) {
			enqueue(p);
			checkvisit[p.x][p.y] = 1;
		}
	}	
	//y<b -> fill b
	if(curr.y < b){
		stt p = initStt(curr.x, b, curr.step + 1);
		if(checkvisit[p.x][p.y] == 0) {
			enqueue(p);
			checkvisit[p.x][p.y] = 1;
		}
	}
	//x>0 -> empty x
	if(curr.x > 0){
		stt p = initStt(0, curr.y, curr.step + 1);
		if(checkvisit[p.x][p.y] == 0) {
			enqueue(p);
			checkvisit[p.x][p.y] = 1;
		}
	}
	//y>0 -> empty y
	if(curr.y > 0){
		stt p = initStt(curr.x, 0, curr.step + 1);
		if(checkvisit[p.x][p.y] == 0) {
			enqueue(p);
			checkvisit[p.x][p.y] = 1;
		}
	}
	//x>0 & y<b -> pour x to y (2 case)
	if(curr.x > 0 && curr.y < b){
		if((curr.x + curr.y) <= b){
			stt p = initStt(0, curr.x + curr.y, curr.step + 1);
			if(checkvisit[p.x][p.y] == 0) {
			enqueue(p);
			checkvisit[p.x][p.y] = 1;
		}	
		}
		else{
			stt p = initStt(curr.x + curr.y - b, b, curr.step + 1);
			if(checkvisit[p.x][p.y] == 0) {
			enqueue(p);
			checkvisit[p.x][p.y] = 1;
		}
		}	
	}
	//x<a & y>0 -> pour y to x (2 case)
	if(curr.x < a && curr.y > 0){
		if((curr.x + curr.y) <= a){
			stt p = initStt(curr.x + curr.y, 0, curr.step + 1);
			if(checkvisit[p.x][p.y] == 0) {
			enqueue(p);
			checkvisit[p.x][p.y] = 1;
		}	
		}
		else{
			stt p = initStt(a, curr.x + curr.y - a, curr.step + 1);
			if(checkvisit[p.x][p.y] == 0) {
			enqueue(p);
			checkvisit[p.x][p.y] = 1;
		}
		}	
	}	
	
}
void initMath(){
	for (int i = 0; i < 1100; i++){
		for(int j = 0; j < 1100; j++){
			checkvisit[i][j] = 0;
		}
	}
	checkvisit[0][0] = 1;
	head = 0;
	tail = 1;
	check = 0;
}
int water(int a, int b, int c){
	printf("%d %d %d\n", head, tail, check);
	printf("vao water a = %d, b = %d\n", a, b);
	initMath();
//	stt q[11000];
	q = (stt*)malloc(11000*sizeof(stt));
	q[0] = initStt(0, 0, 0);
	printf("%d %d %d\n", head, tail, check);
	//
	while(tail >= head){
		printf("queue: ");
		for (int i = head; i <= tail; i++){
			printf("%d-%d:%d, ",q[i].x,q[i].y,q[i].step);
		}
		printf("\n");
		check = checkWater (q, c);
		if(check != 0) break;
		waterJug (/*q,*/ a, b);
	}

	return check;		
}
int main(){
	int n;
	scanf("%d", &n);
	int a[n][3];
	for(int i = 0; i < n; i++){
		scanf("%d", &a[i][0]);
		scanf("%d", &a[i][1]);
		scanf("%d", &a[i][2]);		
	}
	for(int i = 0; i < n; i++){
		int rs = water(a[i][0], a[i][1], a[i][2]);
		printf("%d\n", rs);
	}
	free(q);
}

