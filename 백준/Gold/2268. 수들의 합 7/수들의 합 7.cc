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

	cin >> n >> m;
	height = (int)ceil(log2(n));
	start_index = 1 << height;
	seg_tree.resize((1 << (height + 1)), 0);
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
	for (int i = 0; i < m; i++) {
		int oper, n1, n2;
		cin >> oper >> n1 >> n2;

		if (oper == 0) {
			n1 += start_index - 1;
			n2 += start_index - 1;
			if(n1 < n2) cout << get_partsum(n1, n2)<<"\n";
			else cout << get_partsum(n2, n1) << "\n";
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