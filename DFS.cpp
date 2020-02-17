#include <iostream>
#include <vector> 
using namespace std;

#define MAX 100001

int N, M;
vector<int> A[MAX];

int d[MAX];
int f[MAX];
int p[MAX];
char color[MAX];
int t;
int count;
vector<int> connectedCom[MAX];

void printTable(){
	for(int v= 1; v <= N; v++){
		cout<<"d["<<v<<"] = "<<d[v]<< "  f["<<v<<"] = "<<f[v]<<"  p["<<v<<"] = "<<p[v]<<"  color["<<v<<"] = "<<color[v];
		cout<<endl;
	}
	cout<<endl;
}
/*
	Name: 
	Copyright: 
	Author: 
	Date: 16/12/19 13:34
	Description: 
*/


int input(){
	cin>>N>>M;
	int u,v;
	for(int i = 1; i <= M; i++){	
		cin>>u>>v;
		A[u].push_back(v);
		A[v].push_back(u);
	}
}
void printGraph(){
	for(int v = 1; v <= N; v++){
		cout<<"A["<<v<<"] = ";
		for(int i = 0; i <A[v].size(); i++){
			cout<<A[v][i]<<" ";
		}
		cout<<endl;
	}
}
int findRoute(int s, int t, int haveFind){
	int index = 1;
	int r[MAX];
	r[0] = t;
	int tar = t;
	while(p[tar] != s){
		if(p[tar] == 0) {
			if(haveFind){
				printf("Khong tim duoc");
				return 0;
			}
			else{
				return findRoute(t, s, 1);
			}
		}
		else{
			r[index++] = p[tar];
			tar = p[tar];
		}
	}
	r[index] = s;
	cout<<"Route from "<<s<<" to "<<t<<": ";
	if(haveFind)
		for(int i = 0; i <= index; i++){
			cout<<r[i]<<" ";
		}
	else
		for(int i = index; i >= 0; i--){
			cout<<r[i]<<" ";
		}
	cout<<endl;
	return 1;
}

main(){
	input();
//	printGraph();
	DFS();
	printTable();
	cout<<count<<endl;
	for(int i = 1; i <= count; i++){
		cout<<"Com "<<i<<" : ";
		for(int j = 0; j < connectedCom[i].size(); j++){
			cout<<connectedCom[i][j]<<" ";
		}
		cout<<endl;
	}
//	findRoute(4, 6, 0);
}
