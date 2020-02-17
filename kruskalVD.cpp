#include <bits/stdc++.h>

using namespace std;

const int MAX = 1E6 + 5;
int N, M;
int u[MAX], v[MAX], r[MAX]; //root/rank
long long w[MAX];

void quickSort(int l, int r) {  // sort by weight
	if (l >= r) return;
	int i = l, j = r, x = w[(i+j)/2];
	do {
		while (w[i] < x) i++;
		while (w[j] > x) j--;
		if (i <= j) {
			swap(w[i], w[j]);
			swap(u[i], u[j]);
			swap(v[i], v[j]);
			i++;
			j--;
		}
	} while (i <= j);
	
	quickSort(l, j);
	quickSort(i, r);
}

int input(){
	ios::sync_with_stdio(false);
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		cin >> u[i] >> v[i] >> w[i];
	}
}
int init(){
	for (int i = 1; i <= N; i++) {
		r[i] = -1;
	}
	
}


int root(int x) {
	if (r[x] < 0) {
		return x;
	} else {
		r[x] = root(r[x]);
		return r[x];
	}
}

int merge(int u, int v) {
	if (r[v] < r[u]) {
		swap(u, v);
	}
	r[u] += r[v];
	r[v] = u;
}
long long solve(){
	init();
	quickSort(0, M-1);
	long long res = 0;
	int ru, rv;
	for (int i = 0; i < M; i++) {
		ru = root(u[i]);
		rv = root(v[i]);
		if (ru != rv) {
			merge(ru, rv);
			res += w[i];
		}
	}
	return res;
}
int main() {
	input();
	cout << solve() << endl;
}
