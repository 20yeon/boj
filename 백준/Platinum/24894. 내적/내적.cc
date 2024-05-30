#include <bits/stdc++.h>
#define fastio cin.tie(0)->sync_with_stdio(0)
using namespace std;

using i64 = long long;

struct PLL {
	i64 x, y;
	PLL(const i64 x = 0, const i64 y = 0) : x(x), y(y) {}
	bool operator<= (const PLL& i) const { return 1. * x / y <= 1. * i.x / i.y; }
};

struct ConvexHull {
private:
	static PLL C(const PLL& a, const PLL& b) { return { a.y - b.y, b.x - a.x }; }
	vector<PLL> S;
public:
	void Insert(const i64 a, const i64 b) {
		while (S.size() > 1 && C(S.back(), PLL(a, b)) <= C(S[S.size() - 2], S.back())) S.pop_back();
		S.push_back(PLL(a, b));
	}
	i64 Query(const i64 x, const i64 y) const {
		if (S.empty()) return 0;
		int lo = 0, hi = S.size();
		while (lo + 1 < hi) {
			const int mid = lo + hi >> 1;
			if (C(S[mid - 1], S[mid]) <= PLL(x, y)) lo = mid;
			else hi = mid;
		}
		return S[lo].x * x + S[lo].y * y;
	}
} CHT;

int main() {
	fastio;
	i64 n, res = 0; cin >> n;
	vector<PLL> v(n);
	for (int i = 0; i < n; i++) cin >> v[i].x >> v[i].y;
	sort(v.begin(), v.end(), [](const PLL& a, const PLL& b) {
		return a.x < b.x || a.x == b.x && a.y < b.y;
	});
	for (int i = 0; i < n; i++) {
		if (i + 1 < n && v[i].x == v[i + 1].x) {
			res = max(res, v[i].x * v[i + 1].x + v[i].y * v[i + 1].y);
		}
		else {
			res = max(res, CHT.Query(v[i].x, v[i].y));
			CHT.Insert(v[i].x, v[i].y);
		}
	}
	cout << res << '\n';
}