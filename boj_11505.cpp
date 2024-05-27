#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

const long long MOD = 1000000007;
int n, m, k;
int height, start_index;
vector<long long> seg_tree;

void input() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m >> k;

	height = (int)ceil(log2(n));
	start_index = 1 << height;
	seg_tree.resize((1 << (height + 1)), 1);

	for (int i = 0; i < n; i++) cin >> seg_tree[i + start_index];
}

long long set_tree(int node_num) {
	if (node_num * 2 >= seg_tree.size()) return seg_tree[node_num];
	else return seg_tree[node_num] = (set_tree(node_num * 2) * set_tree(node_num * 2 + 1)) % MOD;
}
long long get_partmul(int start, int end) {
	long long partmul = 1;
	while (start <= end) {
		if (start % 2 != 0) {
			partmul = (partmul * seg_tree[start]) % MOD;
			start++;
		}
		if (end % 2 == 0) {
			partmul = (partmul * seg_tree[end]) % MOD;
			end--;
		}
		start /= 2;
		end /= 2;
	}
	return partmul;
}
void change_val(int node_num, long long val) {
	seg_tree[node_num] = val;

	while (node_num > 1) {
		node_num /= 2;
		seg_tree[node_num] = (seg_tree[node_num * 2] * seg_tree[node_num * 2 + 1]) % MOD;
	}
}

void solve() {
	set_tree(1);

	for (int i = 0; i < m + k; i++) {
		long long oper, n1, n2;
		cin >> oper >> n1 >> n2;
		if (oper == 1) {
			n1 += start_index - 1;
			change_val(n1, n2);
		}
		if (oper == 2) {
			n1 += start_index - 1;
			n2 += start_index - 1;
			cout << get_partmul(n1, n2) << "\n";
		}
	}
}
int main() {
	input();
	solve();

	return 0;
}
