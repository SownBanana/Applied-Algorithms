#include "stdio.h"
#include "string.h"

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
stt dequeue (stt q[]){
	head += 1;
	return q[head-1];
}
stt pop (stt q[]){
	return q[head];
}
void enqueue (stt q[], stt a){
	q[tail] = a;
	tail += 1;
}
int checkWater(stt q[], int c){
	stt p = pop(q);
	if(p.x == c || p.y == c) return p.step;
	return -1;
}
void waterJug (stt q[], int a, int b){
	stt curr = dequeue(q);
	//x<a -> fill a
	if(curr.x < a){
		stt p = initStt(a, curr.y, curr.step + 1);
		if(checkvisit[p.x][p.y] == 0) {
			enqueue(q, p);
			checkvisit[p.x][p.y] = 1;
		}
	}	
	//y<b -> fill b
	if(curr.y < b){
		stt p = initStt(curr.x, b, curr.step + 1);
		if(checkvisit[p.x][p.y] == 0) {
			enqueue(q, p);
			checkvisit[p.x][p.y] = 1;
		}
	}
	//x>0 -> empty x
	if(curr.x > 0){
		stt p = initStt(0, curr.y, curr.step + 1);
		if(checkvisit[p.x][p.y] == 0) {
			enqueue(q, p);
			checkvisit[p.x][p.y] = 1;
		}
	}
	//y>0 -> empty y
	if(curr.y > 0){
		stt p = initStt(curr.x, 0, curr.step + 1);
		if(checkvisit[p.x][p.y] == 0) {
			enqueue(q, p);
			checkvisit[p.x][p.y] = 1;
		}
	}
	//x>0 & y<b -> pour x to y (2 case)
	if(curr.x > 0 && curr.y < b){

		if((curr.x + curr.y) <= b){
			stt p = initStt(0, curr.x + curr.y, curr.step + 1);
			if(checkvisit[p.x][p.y] == 0) {
			enqueue(q, p);
			checkvisit[p.x][p.y] = 1;
			}	
		}
		else{
			stt p = initStt(curr.x + curr.y - b, b, curr.step + 1);
			if(checkvisit[p.x][p.y] == 0) {
			enqueue(q, p);
			checkvisit[p.x][p.y] = 1;
			}
		}	
	}
	//x<a & y>0 -> pour y to x (2 case)
	if(curr.x < a && curr.y > 0){

		if((curr.x + curr.y) <= a){
			stt p = initStt(curr.x + curr.y, 0, curr.step + 1);
			if(checkvisit[p.x][p.y] == 0) {
			enqueue(q, p);
			checkvisit[p.x][p.y] = 1;
			}	
		}
		else{
			stt p = initStt(a, curr.x + curr.y - a, curr.step + 1);
			if(checkvisit[p.x][p.y] == 0) {
			enqueue(q, p);
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
	head = 0;
	tail = 1;
	check = -1;
}
int water(int a, int b, int c){
	if(a<c && b<c) return -1;
	if(a <= 0 || b <= 0 || c <= 0) return -1;
	initMath();
	stt q[110000];
	q[0] = initStt(0, 0, 0);
	
	while(tail >= head){
		check = checkWater (q, c);
		if(check != -1) break;
		waterJug (q, a, b);
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
	return 0;
}

