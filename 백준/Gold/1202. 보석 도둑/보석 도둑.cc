#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int n, k;
long long int res = 0;
pair<int, int>jew[300001];
int bag[300001];

struct jewerly {
	int v;
	jewerly(int y) {
		this->v = y;
	}
	bool operator < (const jewerly& j) const {
		return v < j.v;
	}
};
priority_queue<jewerly> pq_j;


void input() {
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		int m, v; cin >> m >> v;
		jew[i] = { m,v };
	}
	for (int i = 0; i < k; i++) {
		int w; cin >> w;
		bag[i] = w;
	}
	sort(jew, jew + n);
	sort(bag, bag + k);
}

void solve() {
	int idx = 0;
	for (int i = 0; i < k; i++) {
		for (; (jew[idx].first <= bag[i] && idx < n); idx++) {
			pq_j.push(jew[idx].second);
		}
		if (!pq_j.empty()) { res += pq_j.top().v; pq_j.pop(); }
	}
	cout << res;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	input();
	solve();

	return 0;
}
