#include <iostream>
#include <vector>
#include <list>
#define MAX 100001
//using namespace std;
 
typedef struct a{
	int u;
	int w;
} pairWu;
 
int N,M;
int s,t; //start - target
std::vector<pairWu> A[MAX];		//tree

int p[MAX];
bool fixed[MAX];

//heap
int d[MAX];		//d[v] is the upper bound of the length of the shortest path from s to v;
int node[MAX];  //node[i] is the ith element(vertex -u and weight -w) in th HEAP
int idx[MAX]; 	//idx[v] is the index of v in the HEAP (idx[node[i].u] = i) 
int sH; 		//size of HEAP	
 
void input(){
	std::cin>>N>>M;
	for(int i = 0; i < M; i++){
		int u;
		pairWu v;
		std::cin>>u>>v.u>>v.w;
		A[u].push_back(v);
	}
	std::cin>>s>>t;
}


void swap(int i, int j){		//swap ith and jth elements of the HEAP
	int tmp = node[i];
	node[i] = node[j];
	node[j] = tmp;
	idx[node[i]] = i;
	idx[node[j]] = j;
}
void upHeap(int i){
//	printf("sH = %d", sH);
	if(i == 0) return;
	while(i>0){
		int pi = (i-1)/2;
//		printf("pi = %d\n", pi);
		if(d[node[i]] < d[node[pi]]){
			swap(i, pi);
		}else{
			break;
		}
		i = pi;
	}	
}
void downHeap(int i){
	int L = 2*i + 1;
	int R = 2*i +2;
	int maxIdx = i;
	if(L < sH && d[node[L]] < d[node[maxIdx]]) maxIdx = L;
	if(R < sH && d[node[R]] < d[node[maxIdx]]) maxIdx = R;
	if(maxIdx != i){
		swap(i, maxIdx);
		downHeap(maxIdx);
	}
}
void insert(int v, int k){		//add element key = k, value = v into HEAP (v,d[v])
//	printf("insert/n");
	d[v] = k;
	node[sH] = v;
	idx[node[sH]] = sH;
	upHeap(sH);
	sH++;
}
int inHeap(int v){
//	printf("%d o %d cua heap\n", v, idx[v]);
	return idx[v];
}
void updateKey(int v, int k){
	if(d[v] > k){
		d[v] = k;
		upHeap(v);
	}
	else{
		downHeap(v);
	}
	
}
int deleteMin(){
	int sel_node = node[0];
	swap(0, sH - 1);
	sH--;
	downHeap(0);
	return sel_node;
}

void init(){
	sH = 0;
	for(int i = 1; i <= N; i++){
		d[i] = 99999;
		fixed[i] = false;
		p[i] = 0;
		idx[i] = -1;
	}
	for(int i = 0; i < A[s].size(); i++){
		pairWu v = A[s][i];
//		std::cout<<node[0]<<std::endl;
		insert(v.u, v.w);
//		std::cout<<node[0]<<std::endl;
	}
	fixed[s] = true;
}

void LOOP(){
	while(sH>0){
		int u = deleteMin();
		fixed[u] = true;
//		std::cout<<"d["<<u<<"] = "<<d[u]<<std::endl;
		for(int i = 0; i < A[u].size(); i++){
			pairWu v = A[u][i];
//			std::cout<<"d["<<v.u<<"] = "<<d[v.u]<<std::endl;
//			std::cout<<u<<"=>"<<v.u<<" = ";
//			std::cout<<d[u] + v.w<<std::endl;
			if(fixed[v.u]) continue;
			if(inHeap(v.u) == -1){			//v.u <=> w(u,v)
//				printf("%d vao heap\n", v.u);
				int w = d[u] + v.w;
				insert(v.u, w);
			}   
			else{
				if(d[v.u] > d[u] + v.w){
//					printf("upadate %d\n", v.u);
					updateKey(v.u, d[u] + v.w);
				}
			}
		}
	}
}
void solve(){
	init();
	LOOP();
	int rs = d[t];
//	if(!fixed[t]) rs = -1;
	std::cout<<rs;
}
int main(){
	input();
	solve();
}

/*
5 7
2 5 87
1 2 97
4 5 78
3 1 72
1 4 19
2 3 63
5 1 18
1 5
*/
