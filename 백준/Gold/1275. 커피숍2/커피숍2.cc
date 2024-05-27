#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int n, q;
int height, start_index;
vector<long long> seg_tree;

void input() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n >> q;
	height = (int)ceil(log2(n));
	start_index = 1 << height;
	seg_tree.resize((1 << (height + 1)), 0);

	for (int i = 0; i < n; i++) cin >> seg_tree[i + start_index];
}

long long set_tree(int node_num) {
	if (node_num * 2 >= seg_tree.size()) return seg_tree[node_num];
	else return seg_tree[node_num] = set_tree(node_num * 2) + set_tree(node_num * 2 + 1);
}

long long get_partsum(long long start, long long end) {
	long long part_sum = 0;

	while (start <= end) {
		if (start % 2 != 0) {
			part_sum += seg_tree[start];
			start++;
		}
		if (end % 2 == 0) {
			part_sum += seg_tree[end];
			end--;
		}
		start /= 2;
		end /= 2;
	}return part_sum;
}

void change_value(long long node_num, long long value) {
	long long diff = value - seg_tree[node_num];

	while (node_num > 0) {
		seg_tree[node_num] += diff;
		node_num /= 2;
	}
}

void solve() {
	set_tree(1);

	for (int i = 0; i < q; i++) {
		long long x, y, a, b;
		cin >> x >> y >> a >> b;

		x += start_index - 1;
		y += start_index - 1;
		a += start_index - 1;

		if (x < y) cout << get_partsum(x, y) << "\n";
		else cout << get_partsum(y, x) << "\n";
		change_value(a, b);
	}
}

int main() {
	input();
	solve();
	return 0;
}