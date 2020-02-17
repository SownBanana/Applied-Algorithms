#include <iostream>
#include <vector>
#include <list>
#define MAX 2000001
//using namespace std;
 

typedef struct a{
	int u;
	int w;
} pairWu;

 
int N,M,k;

std::vector<pairWu> A[MAX];		//tree

int r[MAX];
int p[MAX];
bool fixed[MAX];

//heap
int d[MAX];		//d[v] is the upper bound of the length of the shortest path from s to v;
//std::vector<int> d[MAX];	//d[a][b] is the upper bound of the length of the shortest path from s to v;
int node[MAX];  //node[i] is the ith element(vertex -u and weight -w) in th HEAP
int idx[MAX]; 	//idx[v] is the index of v in the HEAP (idx[node[i].u] = i) 
int sH; 		//size of HEAP	

void input(){
	std::cin>>N>>M;
	for(int i = 0; i < M; i++){
		pairWu u;
		pairWu v;
		std::cin>>u.u>>v.u>>v.w;
		u.w = v.w;
		A[u.u].push_back(v);
		A[v.u].push_back(u);
	}
	std::cin>>k;
	for(int i = 0; i <k; i++){
		std::cin>>r[i];
	}
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
 
void init(int a){
	sH = 0;
	for(int i = 1; i <= N; i++){
		d[i] = 99999;
		fixed[i] = false;
		p[i] = 0;
		idx[i] = -1;
	}
	for(int i = 0; i < A[a].size(); i++){
		pairWu v = A[a][i];
//		std::cout<<node[0]<<std::endl;
		insert(v.u, v.w);
//		std::cout<<node[0]<<std::endl;
	}
	fixed[a] = true;
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

void distance(int a){
	init(a);
	LOOP();
//	int rs = d[b];
//	if(!fixed[t]) rs = -1;
}


int solve(){
	int rs = 0;
	for(int i = 0; i < k-1; i++){
		distance(r[i]);
		for(int j = i+1; j < k; j++){
//			std::cout<<"from "<<r[i]<<" to "<<r[j]<<" = "<<d[r[j]]<<std::endl;
			if(i!=j) {
				if(d[r[j]] > rs) rs = d[r[j]];
			}
		}
	}
	return rs;
}
int main(){
	input();
//	DFS();
	std::cout<<solve();
}

/*

6 10
1 2 2
1 5 6
1 6 1
2 3 8
2 6 4
3 4 7
3 6 2
4 5 3
4 6 5
5 6 4
3
1 3 4

*/
