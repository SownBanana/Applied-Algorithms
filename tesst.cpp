#include "stdio.h"
#include "string.h"

int checkvisit[1100][1100];
typedef struct stt{
	int x;
	int y;
}stt;

stt initStt ( int a, int b){
	stt s;
	s.x = a;
	s.y = b;
	return s;
}
void dequeue (stt q[], int &head){
	head += 1;
 }
void enqueue (stt q[], int &tail, stt a){
	tail += 1;
	q[tail] = a;

}
int waterjug(stt q[], int &head, int &tail, int a, int b, int c, int count){
	if(head < tail){
		printf("head: %d, %d\n", q[head].x,q[head].y);
		printf("+1  :%d, %d\n", q[head+1].x,q[head+1].y);
		printf("+2  :%d, %d\n", q[head+2].x,q[head+2].y);
		if(checkvisit[q[head].x][q[head].y] != 0) {
			dequeue(q, head);
			return -1;	
		} 
		if(q[head].x == c || q[head].y == c) return count + 1;
			else {
				checkvisit[q[head].x][q[head].y] = 1;
				dequeue(q, head);
				if(q[head].x < a) {
					stt _1 = initStt(a,q[head].y);
					enqueue(q,tail,_1);
				}
				if(q[head].y < b) {
					stt _2 = initStt(q[head].x, b);
					enqueue(q,tail,_2);
				}
				if(q[head].x != 0 && q[head].y != b){
					stt _3 = initStt(0, q[head].y);
					enqueue(q,tail,_3);
				}
				if(q[head].y != 0 && q[head].x != a){
					stt _4 = initStt(q[head].x, 0);
					enqueue(q,tail,_4);
				}
				if(q[head].x+q[head].y < b){
					stt _5 = initStt(0, q[head].x+q[head].y);
					enqueue(q,tail,_5);
				}
				if(q[head].x+q[head].y < a){
					stt _6 = initStt(q[head].x+q[head].y, 0);
					enqueue(q,tail,_6);
				}
				if(q[head].x+q[head].y > b){
					stt _7 = initStt(q[head].x - (b-q[head].y),b);
					enqueue(q,tail,_7);
				}
				if(q[head].x+q[head].y > a){
					stt _8 = initStt(a, q[head].y - (a - q[head].x));
					enqueue(q,tail,_8);
				}
			return	waterjug(q,head,tail,a,b,c,count);
			}	
	}
	return -1;
	
}

int water(int a, int b, int c){
	printf("vaof day");
	if (c > a && c > b) return -1;
	if (c == a || c == b) return 1;
	else {
		int count = 1;
		stt q[11000];
		q[0] = initStt(a, 0);
		q[1] = initStt(0, b);
		int tail = 1;
		int head = 0;
		while(tail >= head){
			int rs = waterjug(q, head, tail, a, b, c, count);
			if (rs != 0 && rs != -1) break;
		}
		
	}
}

int main(){
	
	for (int i = 0; i < 1100; i++){
		for(int j = 0; j < 1100; j++){
			checkvisit[i][j] = 0;
		}
	}
	checkvisit[0][0] = 1;
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
}
