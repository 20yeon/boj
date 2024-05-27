#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int n, m;
int height, start_index;
vector<long long> seg_tree;

void input() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n;
	height = (int)ceil(log2(n));
	start_index = 1 << height;
	seg_tree.resize((1 << (height + 1)), 0);
	
	for (int i = 0; i < n; i++) cin >> seg_tree[i + start_index];
}

long long set_tree(int node_num) {
	if (node_num * 2 >= seg_tree.size()) return seg_tree[node_num];
	else return seg_tree[node_num] = min(set_tree(node_num * 2),set_tree(node_num * 2 + 1));
}

long long get_min(long long start, long long end) {
	long long res = 1000000001;
	while (start <= end) {
		if (start % 2 != 0) {
			if (res > seg_tree[start]) res = seg_tree[start];
			start++;
		}
		if (end % 2 == 0) {
			if (res > seg_tree[end]) res = seg_tree[end];
			end--;
		}
		start /= 2;
		end /= 2;
	}return res;
}


void change_value(long long node_num, long long value) {
	seg_tree[node_num] = value;

	while (node_num > 0) {
		node_num /= 2;
		seg_tree[node_num] = min(seg_tree[node_num * 2], seg_tree[node_num * 2 + 1]);
	}
}

void solve() {
	set_tree(1);
	cin >> m;
	for (int i = 0; i < m; i++) {
		int oper, n1, n2;
		cin >> oper >> n1 >> n2;

		if (oper == 2) {
			n1 += start_index - 1;
			n2 += start_index - 1;
			cout << get_min(n1, n2)<<"\n";
		}
		else {
			n1 += start_index - 1;
			change_value(n1, n2);
		}
	}
}

int main() {
	input();
	solve();
	return 0;
}