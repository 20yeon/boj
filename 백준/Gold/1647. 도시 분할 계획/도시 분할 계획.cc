#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int n, m, res = 0;
int village[100001];
struct node {
	int start, end, wei;
	node(int x, int y, int z) {
		this->start = x;
		this->end = y;
		this->wei = z;
	}
	bool operator < (const node& n) const {
		return this->wei > n.wei;
	}
};

priority_queue<node> pq;

void input() {
	cin >> n>> m;
	for (int i = 1; i <= n; i++) village[i] = i;
	for (int i = 0; i < m; i++) {
		int start, end, wei; 
		cin >> start>> end>> wei;
		pq.push(node(start, end, wei));
	}
}

int Find(int x) {
	if (x == village[x]) return x;
	else return village[x] = Find(village[x]);
}

void Union(int x, int y) {
	x = Find(x);
	y = Find(y);

	if (x < y) village[y] = x;
	else village[x] = y;
}

void solve() {
	long long res = 0;
	int max = 0;


	while (!pq.empty()) {
		const auto [start, end, wei] = pq.top();
		pq.pop();
		if (Find(start) == Find(end)) continue;
		else {
			res += wei;
			max = (max < wei) ? wei : max;
			Union(start, end);
		}
	}
	cout << res - max;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	input();
	solve();

	return 0;
}