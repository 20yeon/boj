#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int n;
long long res = 0;
int height, start_index;
vector<int> seg_tree;

void change_value(int node_num) {
	seg_tree[node_num] = 1;

	while (node_num > 1) {
		node_num /= 2;
		seg_tree[node_num] = seg_tree[node_num * 2] + seg_tree[node_num * 2 + 1];
	}
}
int get_partsum(int start, int end) {
	int partsum = 0;
	while (start <= end) {
		if (start % 2 != 0) {
			partsum += seg_tree[start];
			start++;
		}
		if (end % 2 == 0) {
			partsum += seg_tree[end];
			end--;
		}
		start /= 2;
		end /= 2;
	}return partsum;
}
void solve() {
	cin >> n;
	height = (int)ceil(log2(n));
	start_index = 1 << height;

	seg_tree.resize(1 << (height + 1), 0);
	for (int i = 0; i < n; i++) {
		int num; cin >> num;
		num += start_index - 1;

		change_value(num);

		res += get_partsum(num + 1, start_index + n - 1);
	}
	cout << res;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	solve();

	return 0;
}