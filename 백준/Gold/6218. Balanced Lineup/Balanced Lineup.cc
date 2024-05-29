#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int n, q;
int height, start_index;
vector<pair<int, int>> seg_tree;

pair<int, int> set_tree(int node_num) {
	if (node_num * 2 >= seg_tree.size()) return seg_tree[node_num];
	else {
		const auto [left_max, left_min] = set_tree(node_num * 2);
		const auto [right_max, right_min] = set_tree(node_num * 2 + 1);
		if (left_min == 0 && left_max == 0) return seg_tree[node_num] = { 0,0 };
		else {
			if (right_min == 0 && right_max == 0) return seg_tree[node_num] = { left_max, left_min };
			else return seg_tree[node_num] = { max(left_max, right_max), min(left_min,right_min) };
		}
	}
}

void input() {
	cin >> n >> q;

	height = (int)ceil(log2(n));
	start_index = 1 << height;

	seg_tree.resize((1 << (height + 1)), { 0,0 });
	for (int i = 0; i < n; i++) {
		int h; cin >> h;
		seg_tree[i + start_index] = { h,h };
	}
	set_tree(1);
}

int solve(int start, int end) {
	int partmax = 0;
	int partmin = 1000001;

	while (start <= end) {
		if (start % 2 != 0) {
			partmax = (partmax < seg_tree[start].first) ? seg_tree[start].first : partmax;
			partmin = (partmin > seg_tree[start].second) ? seg_tree[start].second : partmin;
			start++;
		}
		if (end % 2 == 0) {
			partmax = (partmax < seg_tree[end].first) ? seg_tree[end].first : partmax;
			partmin = (partmin > seg_tree[end].second) ? seg_tree[end].second : partmin;
			end--;
		}
		start /= 2;
		end /= 2;
	}
	return (partmax - partmin);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	input();
	for (int i = 0; i < q; i++) {
		int n1, n2;
		cin >> n1 >> n2;
		n1 += start_index - 1;
		n2 += start_index - 1;
		cout << solve(n1, n2) << "\n";
	}
	return 0;
}